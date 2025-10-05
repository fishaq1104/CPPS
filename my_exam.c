#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>

char *msg[65536];
int id[65536];

fd_set a_fds, w_fds, r_fds;

int count = 0, max_fd =0;

char buf_read[1001];
char buf_write[42];


int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error()
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

void notify_other(int fd_, char *la)
{
    for(int fd =0; fd <= max_fd ; fd++)
    {
        if(FD_ISSET(fd, &w_fds) && fd != fd_)
            send(fd, la, strlen(la), 0);
    }
}

void create_client(int fd)
{
    max_fd = fd > max_fd ? fd : max_fd;
    id[fd] = count++;
    msg[fd] = NULL;
    FD_SET(fd, &a_fds);
    sprintf(buf_write, "server: client %d just arrived\n", id[fd]);
    notify_other(fd, buf_write);
}

void clear_client(int fd)
{
    sprintf(buf_write, "server: client %d just left\n", id[fd]);
    notify_other(fd, buf_write);
    free(msg[fd]);
    FD_CLR(fd, &a_fds);
    close(fd);
    /*missing something*/
}


void send_msg(int fd)
{
    char *msgs;

    while(extract_message(&(msg[fd]), &msgs))
    {
        sprintf(buf_write, "client %d: ", id[fd]);
        notify_other(fd, buf_write);
        notify_other(fd, msgs);
        free(msgs);
    }
}

int create_socket()
{
    max_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(max_fd < 0)
        fatal_error();
    FD_SET(max_fd, &a_fds);
    return max_fd;
}


int main(int ac, char **av)
{
    if(ac != 2)
    {
        write(2,"Wrong number of arguments\n" , 26);
        exit(1);
    }
    int sockfd;
	struct sockaddr_in servaddr;

    FD_ZERO(&a_fds);
	sockfd = create_socket();
	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))))
        fatal_error();
	if (listen(sockfd, SOMAXCONN))
        fatal_error();
    while (1)
    {
        w_fds = a_fds;
        r_fds = a_fds;
        if(select(max_fd+1, &r_fds, &w_fds, NULL, NULL) < 0)
            fatal_error();
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(!FD_ISSET(fd, &r_fds))
                continue;
            if(sockfd == fd)
            {
                socklen_t lenght = sizeof(servaddr);
                int client = accept(sockfd, (struct sockaddr *)&servaddr, &lenght);
                if(client >= 0)
                {
                    create_client(client);
                    break;
                }
            }
            else
            {
                int read_bytes = recv(fd,buf_read,1000,0);
                if(read_bytes <= 0)
                {
                    clear_client(fd);
                    break;
                }
                buf_read[read_bytes] = '\0';
                msg[fd] = str_join(msg[fd], buf_read);
                send_msg(fd);              
            }
        }
    }
    return(0);
}



// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>
// #include <netdb.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <sys/select.h>

// #define MAX_MSG_SIZE 1000000
// #define MAX_CLIENT 1024

// int current_id = 0;
// int maxfd = 0;

// typedef struct s_client
// {
//     int id;
//     char msg[MAX_MSG_SIZE];
// }t_client;

// t_client clients[MAX_CLIENT];

// fd_set read_set;
// fd_set write_set;
// fd_set current;

// char *send_buf[MAX_MSG_SIZE];
// char *recv_buff[MAX_MSG_SIZE];

// void putstr(int i, char *msg)
// {
//     for(int i=0; msg[i] != '\0'; i++)
//     {
//         write(i, &msg[i], 1);
//     }
// }

// void err(char *msg)
// {
//     if(!msg)
//         putstr(2, "Fatol Error\n");
//     else
//         putstr(2, msg);
//     exit(1);
// }

// int main(int ac, char *av)
// {
//     if(ac!= 2)
//         err("Wrong number of arguments\n");
    
//     int socketfd, confd;
//     struct sockaddr_in serv;

//     socketfd = socket(AF_INET, SOCK_STREAM, 0);
//     if(socketfd == -1)
//         err(NULL);
//     bzero(&serv, sizeof(serv));

//     FD_ZERO(&current);
//     FD_SET(socketfd, &current);
//     maxfd = socketfd;

//     serv.sin_family = AF_INET;
//     serv.sin_addr.s_addr = htonl(2130706433);
//     serv.sin_port = htons(atoi(av[1]));

//     if(bind(socketfd, (const struct sockaddr *)&serv,sizeof(serv)) != 0)
//         err(NULL);
    
//     if(listen(socketfd, 10) != 0)
//         err(NULL);

//     while(1)
//     {
//         read_set = write_set = current;
//         if(select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
//             err(NULL);
//         for(int fd =0; fd <= maxfd; fd++)
//         {
//             if(FD_ISSET(fd, &read_set))
//             {
//                 struct sockaddr_in cli;
//                 bzero(&cli, sizeof(cli));
//                 socklen_t len = sizeof(cli);
//                 confd = accept(socketfd,  (const struct sockaddr *)&cli, len);
//                 if(confd < 0)
//                     err(NULL);
//                 if(confd > maxfd)
//                     maxfd = confd;
//                 clients[confd].id = current_id;
//                 current_id++;
//                 FD_SET(confd, &current);
//                 sprintf(send_buf, "server:client %d just arrived\n", clients[confd].id);
//                 send_broadcast(confd);
//             }
//             else
//             {
//                 int ret = recv(fd, recv_buff, MAX_MSG_SIZE, 0);
//                 if(ret <= 0)
//                 {
//                     sprintf(send_buf, "server:client %d just arrived\n", clients[fd].id);
//                     send_broadcast(fd);
//                     FD_CLR(fd, &current);
//                     close(fd);
//                 }
//                 else
//                 {
//                     for(int i = 0, j = strlen(clients[fd].msg); i  < ret; i++, j++)
//                     {
//                         clients[fd].msg[j] = recv_buff[i];
//                         sprintf(send_buf, "client %d: %s\n", clients[fd].id, clients[fd].msg);
//                         send_broadcast(fd);
//                         bzero(clients[fd].msg, strlen(clients[fd].msg));
//                         j = -1;
//                     }
//                 }
//             }
//         }
//     }
// }
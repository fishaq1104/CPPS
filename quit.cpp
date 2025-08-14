#include "Numerical_Replies_.hpp"
#include "command.hpp"
#include "Channel.hpp"
#include "Server.hpp"
#include "Client.hpp"

std::string	getReason(std::string msg_to_parse)
{
	std::string reason;
	
	reason.clear(); // by default let's say there is no reason = "#hey"
	
	if (msg_to_parse.find(":") != msg_to_parse.npos) // If there is a ":", there is a reason => "#hey :bonjour"
		reason.append(msg_to_parse, msg_to_parse.find(":") + 1, std::string::npos);
	return (reason);
}

void quit(Server* serv, int fd, struct cmd_struct cmds)
{
    (void)fd;
    (void)serv;
    (void)cmds;
    // Client &client = reciveClient(serv, fd);
    // std::string reason = ge;
}
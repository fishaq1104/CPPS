#include "command.hpp"
#include "Numerical_Replies_.hpp"



bool containsAtLeastOneAlphaChar(std::string &message)
{
    if (message[0] == ' ')
        message.erase(0, 1);
    if (message.find(" ") != message.npos)
        message = message.substr(0, message.find(" "));
    for(int i = 0; i < message.length(); i++)
    {
        if(isalpha(message[i]))
            return true;
    }
    return false;
}

// std::string getChannelName(std::string &s)
// {
//     std::string channel;

//     size_t i = 0;

//     while(s[i] && (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '-' && s[i] != '_'))
//         i++;
//     while(s[i] && (!isalpha(s[i]) || !isdigit(s[i]) || s[i] != '-' || s[i] != '_'))
//     channel += s[i++];
//     return channel;
// }

std::string getChannelName(std::string &s)
{
    std::string channel_name;
    size_t i = s.find('#');
    
    if (i == std::string::npos)
        return "";
    
    while (i < s.size() && (s[i] == '#' || isalnum(s[i]) || s[i] == '-' || s[i] == '_'))
        channel_name += s[i++];
    return channel_name;
}

void addChannel(std::map<std::string, Channel> &channels, std::string &s)
{
    std::map<std::string, Channel>::iterator it = channels.find(s);
    if(it != channels.end())
    {
        std::cout << "Channel already exists, choose an other name" << std::endl;
		return ;
    }
    Channel channel(s);
    channels.insert(std::pair<std::string, Channel>(s, channel));
}

void join(Server* serv, int fd, struct cmd_struct cmds)
{
    Client &client = reteriveClient(fd); //utils
    std::string Nickname = client.getNickName();
    std::string channel_name;
   
    if (cmds.message.empty() || !containsAtLeastOneAlphaChar(cmds.message))
        addClientBuffer(serv, fd, ERR_NEEDMOREPARAMS(Nickname, cmd.name));

    while(containsAtLeastOneAlphaChar(cmds.message))
    {
        channel_name = getChannelName(cmds.mesggae);
        cmds.message.erase(cmds.message.find(channel_name), channel_name.length());
        
        std::map<std::string, Channel>& channels = serv->getChannels();
        std::map<std::string, Channel>::iterator it = channels.find(channel_name);
        if(it == channels.end())
            addChannel(channels, channel_name);
        else if(it->second.getMode().find('k') != std::string::npos) // Mode add it okay to the channels okay
        //like map for he mdoe okay 
        {

        }

    }
}



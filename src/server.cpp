#include "../include/server.hpp"

#include <iostream>

void Server::ListAllChannels()
{
    std::cout << channels.size() << std::endl;
    std::cout << "#Canais de texto: " << std::endl;
    for (int i = 0; i < channels.size(); i++)
    {
        if (channels[i]->GetType() == "TextChannel")
        {
            std::cout << channels[i]->GetName() << std::endl;
        }
    }
    std::cout << "#Canais de audio: " << std::endl;
    for (int i = 0; i < channels.size(); i++)
    {
        if (channels[i]->GetType() == "VoiceChannel")
        {
            std::cout << channels[i]->GetName() << std::endl;
        }
    }
}
void Server::CreateChannel(std::string name, std::string type)
{

    for (Channel *channel : channels)
    {

        if (channel->GetName() == name && channel->GetType() == type)
        {
            std::cout << channel->GetName() << "Ja Existe!" << std::endl;
            return;
        }
    }

    if (type == "TextChannel")
    {
        TextChannel *newTextChannel = new TextChannel(name, type);
        channels.push_back(newTextChannel);
        std::cout << "TextChannel " << name << " Criado!" << std::endl;
    }
    else if (type == "VoiceChannel")
    {
        VoiceChannel *newVoiceChannel = new VoiceChannel(name, type);
        channels.push_back(newVoiceChannel);
        std::cout << "VoiceChannel " << name << " Criado! " << std::endl;
    }
}
bool Server::IsOpen() const
{
    return inviteCode.empty();
}

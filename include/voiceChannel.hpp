#ifndef VOICECHANNEL_HPP
#define VOICECHANNEL_HPP
#include "channel.hpp"
#include "message.hpp"

/**
 * @brief classe voice channel onde os canais de voz serão gerenciados
 *
 */
class VoiceChannel : private Channel
{
private:
    Message lastMessage;

public:
    VoiceChannel(std::string name) : Channel(name), lastMessage() {}

    Message GetLastMessage()
    {
        return lastMessage;
    }
    void SetMessage(Message newMessage)
    {
        lastMessage = newMessage;
    }
};

#endif
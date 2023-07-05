#ifndef VOICECHANNEL_HPP
#define VOICECHANNEL_HPP
#include "channel.hpp"
#include "message.hpp"

/**
 * @brief classe voice channel onde os canais de voz serão gerenciados, herda da classe Channel
 *
 */
class VoiceChannel : public Channel
{
private:
    Message lastMessage;
    std::vector<Message> voiceMessages;

public:
    VoiceChannel(std::string &name) : Channel(name), lastMessage() {}
    VoiceChannel(std::string name, std::string type) : Channel(name, type), lastMessage() {}

    Message GetLastMessage() const
    {
        return lastMessage;
    }
    void SetMessage(Message newMessage)
    {
        lastMessage = newMessage;
    }
    void NewMessage(Message newMessageSent)
    {
        voiceMessages.push_back(newMessageSent);
    }
    std::vector<Message> GetMessages()
    {
        return voiceMessages;
    }
};

#endif
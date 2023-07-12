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

    /**
     * @brief função Get Para retornar a ultima mensagem
     *
     * @return Message
     */
    Message GetLastMessage() const
    {
        return lastMessage;
    }
    /**
     * @brief Seta nova mensagem
     *
     * @param newMessage
     */
    void SetMessage(Message newMessage)
    {
        lastMessage = newMessage;
    }
    /**
     * @brief função para adcionar nova mensagem no vetor de mensagens
     *
     * @param newMessageSent
     */
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
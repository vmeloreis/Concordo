#ifndef TEXTCHANNEL_HPP
#define TEXTCHANNEL_HPP
#include "channel.hpp"
#include "message.hpp"
#include <vector>

/**
 * @brief classe textChannel onde os canais de texto serão gerenciados, herda da classe Channel
 *
 */
class TextChannel : public Channel
{
private:
    std::vector<Message> messages;

public:
    TextChannel(std::string &name) : Channel(name) {}
    TextChannel(std::string name, std::string type) : Channel(name, type) {}

    /**
     * @brief função newMessage para enviar mensagem nova no vetor messages
     *
     * @param newMessageSent
     */
    void NewMessage(Message newMessageSent)
    {
        messages.push_back(newMessageSent);
    }
    /**
     * @brief Função Get Para retornar o vetor de mensagens
     *
     * @return std::vector<Message>
     */
    std::vector<Message> GetMessages()
    {
        return messages;
    }
};

#endif
#ifndef CANAL_HPP
#define CANAL_HPP
#include <string>
#include <vector>
#include "message.hpp"

/**
 * @brief  classe canal onde os canais serão gerenciados
 *
 */

class Channel
{

private:
    std::string channelName;
    std::string type;

public:
    Channel(std::string name)
    {
        channelName = name;
    }
    Channel(std::string channelNewName, std::string newType)
    {
        channelName = channelNewName;
        type = newType;
    }
    Channel() {}
    ~Channel() {}

    /**
     * @brief Função Get Para retornar o nome do canal
     *
     * @return std::string
     */
    std::string GetName() const
    {
        return channelName;
    }
    /**
     * @brief Função Get Para retornar o tipo do canal
     *
     * @return std::string
     */
    std::string GetType() const
    {
        return type;
    }
    /**
     * @brief função virtual para enviar mensagem
     *
     * @param newMessageSent mensagem a ser enviada
     */
    virtual void NewMessage(Message newMessageSent) = 0;
    /**
     * @brief função Get Para retornar o vetor de mensagens
     *
     * @return std::vector<Message>
     */
    virtual std::vector<Message> GetMessages() = 0;
};

#endif
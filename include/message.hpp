#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <chrono>
#include <iomanip>

/**
 * @brief classe message onde as mensagens serão gerenciadas
 *
 */
class Message
{
private:
    std::chrono::system_clock::time_point time; /**< tempo da mensagem*/
    int sentBy;                                 /**< ID da pessoa que enviou a mensagem*/
    std::string content;                        /**< conteúdo da mensagem*/

public:
    /**
     * @brief Construtor padrao para inicializar os atributos da mensagem
     *
     * @param time tempo da mensagem
     * @param sentBy id de quem enviou
     * @param content conteúdo da mensagem
     */
    Message(std::chrono::system_clock::time_point time, int sentBy, std::string content)
        : time(time), sentBy(sentBy), content(content)
    {
    }
    /**
     * @brief Construtor com mensagem vazia
     *
     * @param time tempo da mensagem
     * @param sentBy id de quem enviou
     */
    Message(std::chrono::system_clock::time_point time, int sentBy)
        : time(time), sentBy(sentBy)
    {
        content = "";
    }

    Message()
    {
        content = "";
    }

    ~Message() {}

    /**
     * @brief Função Get Para retornar o id de quem enviou a mensagem
     *
     * @return int id de quem enviou
     */
    int GetAuthor() const
    {
        return sentBy;
    }

    /**
     * @brief Função Get Para retornar o tempo em que a mensagem foi enviada
     *
     * @return std::chrono::system_clock::time_point tempo da mensagem
     */
    std::chrono::system_clock::time_point GetTime() const
    {
        return time;
    }

    /**
     * @brief Função Get Para retornar o conteúdo da mensagem
     *
     * @return std::string conteudo da mensagem
     */
    std::string GetMessage() const
    {
        return content;
    }
};

#endif
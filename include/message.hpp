#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <string>

/**
 * @brief classe message onde as mensagens serão gerenciadas
 *
 */
class Message
{
private:
    std::string time;
    int sentBy;
    std::string content;

public:
    Message(std::string time, int sentBy, std::string content)
    {
        this->time = time;
        this->sentBy = sentBy;
        this->content = content;
    }
    Message(std::string time, int sentBy)
    {
        content = "";
        this->sentBy = sentBy;
        this->time = time;
    }
    Message()
    {
        content = "";
    }

    ~Message() {}
};

#endif
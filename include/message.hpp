#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <chrono>

/**
 * @brief classe message onde as mensagens serão gerenciadas
 *
 */
class Message
{
private:
    std::chrono::system_clock::time_point time;
    int sentBy;
    std::string content;

public:
    Message(std::chrono::system_clock::time_point time, int sentBy, std::string content)
        : time(time), sentBy(sentBy), content(content)
    {
    }

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

    int GetAuthor()
    {
        return sentBy;
    }

    std::chrono::system_clock::time_point GetTime()
    {
        return time;
    }

    std::string GetMessage()
    {
        return content;
    }
};

#endif
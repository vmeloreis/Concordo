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
    std::string GetName() const
    {
        return channelName;
    }
    std::string GetType() const
    {
        return type;
    }

    virtual void NewMessage(Message newMessageSent) = 0;
    virtual std::vector<Message> GetMessages() = 0;
};

#endif
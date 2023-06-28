#ifndef CANAL_HPP
#define CANAL_HPP
#include <string>

/**
 * @brief  classe canal onde os canais serão gerenciados
 *
 */
class Channel
{
private:
    std::string channelName;

public:
    Channel(std::string channelNewName)
    {
        channelName = channelNewName;
    }
    Channel() {}
    ~Channel() {}
    std::string GetName()
    {
        return channelName;
    }
};

#endif
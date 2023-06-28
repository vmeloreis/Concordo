#ifndef TEXTCHANNEL_HPP
#define TEXTCHANNEL_HPP
#include "channel.hpp"
#include "message.hpp"
#include <vector>

/**
 * @brief classe textChannel onde os canais de texto serão gerenciados
 *
 */
class TextChannel : private Channel
{
private:
    std::vector<Message> messages;
};

#endif
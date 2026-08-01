#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

enum class CommandType
{
    SPAWN,
    LIST,
    UNKNOWN
};

struct Command
{
    CommandType type;
    unsigned int id;
    std::string username;
    std::string email;
};

#endif  
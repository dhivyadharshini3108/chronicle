#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

#include "command.hpp"

enum class ParseResult
{
    SUCCESS,
    SYNTAX_ERROR
};

ParseResult parseCommand(const std::string& input,
                         Command& command,
                         std::string& errorMessage);

#endif
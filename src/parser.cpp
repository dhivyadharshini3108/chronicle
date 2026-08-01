#include "parser.hpp"

#include <sstream>

ParseResult parseCommand(const std::string& input,
                         Command& command,
                         std::string& errorMessage)
{
    std::stringstream ss(input);

    std::string word1, word2;

    ss >> word1 >> word2;

    if(word1 == "LIST" && word2 == "PLAYERS")
    {
        command.type = CommandType::LIST;
        return ParseResult::SUCCESS;
    }

    if(word1 == "SPAWN" && word2 == "PLAYER")
    {
        command.type = CommandType::SPAWN;

        int id;

        if(!(ss >> id >> command.username >> command.email))
        {
            errorMessage = "Syntax error.";
            return ParseResult::SYNTAX_ERROR;
        }

        if(id <= 0)
        {
            errorMessage = "ID must be positive.";
            return ParseResult::SYNTAX_ERROR;
        }

        command.id = static_cast<unsigned int>(id);
        if(command.username.length() > 32)
        {
            errorMessage = "username too long (max 32 chars).";
            return ParseResult::SYNTAX_ERROR;
        }

        if(command.email.length() > 255)
        {
            errorMessage = "email too long (max 255 chars).";
            return ParseResult::SYNTAX_ERROR;
        }

        return ParseResult::SUCCESS;
    }
    errorMessage = "Syntax error.";
    return ParseResult::SYNTAX_ERROR;
}
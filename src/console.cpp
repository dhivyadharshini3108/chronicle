#include <iostream>
#include <string>

#include "console.hpp"
#include "input_buffer.hpp"
#include "command_dispatcher.hpp"
#include "application_state.hpp"
#include "parser.hpp"
#include "executer.hpp"
#include "world_state.hpp"

void startConsole()
{
    InputBuffer buffer;
    WorldState world;

    while (true)
    {
        std::cout << "ironhold> ";

        std::string input;
        std::getline(std::cin, input);

        buffer.setCommand(input);

        std::string commandText = buffer.getCommand();

        if(commandText.empty())
        {
            continue;
        }

        // -------------------------
        // Milestone 1 System Commands
        // -------------------------
        if(commandText[0] == '.')
        {
            AppState state = dispatchCommand(commandText);

            if(state == AppState::EXIT)
            {
                break;
            }

            continue;
        }

        // -------------------------
        // Milestone 2 World Commands
        // -------------------------
        Command command;
        std::string errorMessage;

        ParseResult result = parseCommand(commandText,
                                          command,
                                          errorMessage);

        if(result == ParseResult::SUCCESS)
        {
            execute(command, world);
        }
        else
        {
            std::cout << "Error: " << errorMessage << std::endl;
        }
    }
}
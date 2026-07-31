#include <iostream>

#include "command_dispatcher.hpp"

AppState dispatchCommand(const std::string& command)
{
    if(command == ".help")
    {
        std::cout << "  .quit       Shut down the world engine\n";
        std::cout << "  .help       Show this message\n";
        std::cout << "  .version    Show engine version\n";
        std::cout << "  .status     Show world status\n";

        return AppState::RUNNING;
    }

    else if(command == ".version")
    {
        std::cout << "Chronicle v0.1 - Ironhold World Engine\n";
        return AppState::RUNNING;
    }

    else if(command == ".status")
    {
        std::cout << "World: offline\n";
        return AppState::RUNNING;
    }

    else if(command == ".quit")
    {
        return AppState::EXIT;
    }

    else if(!command.empty() && command[0] == '.')
    {
        std::cout << "Unknown command. Try .help\n";
        return AppState::UNKNOWN;
    }

    else
    {
        std::cout << "[World command queued: " << command << "]\n";
        return AppState::RUNNING;
    }
}
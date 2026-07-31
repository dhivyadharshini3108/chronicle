#include <iostream>
#include <string>

#include "command_dispatcher.hpp"
#include "application_state.hpp"
#include "console.hpp"
#include "input_buffer.hpp"

void startConsole()
{
    InputBuffer buffer;
    while(true)
    {
        std::cout<<"ironhold> ";
        std::string input;
        std::getline(std::cin,input);
        buffer.setCommand(input);
        AppState state = dispatchCommand(buffer.getCommand());

        if(state == AppState::EXIT)
        {
            break;
        }
    }
}
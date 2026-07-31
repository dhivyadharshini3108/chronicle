#include "input_buffer.hpp"

void InputBuffer::setCommand(const std::string& input)
{
    size_t start = input.find_first_not_of(" \t");
    size_t end = input.find_last_not_of(" \t");

    if(start == std::string::npos)
    {
        command = "";
    }
    else
    {
        command = input.substr(start, end - start + 1);
    }

    historyLength++;
}

std::string InputBuffer::getCommand() const
{
    return command;
}

int InputBuffer::getHistoryLength() const
{
    return historyLength;
}
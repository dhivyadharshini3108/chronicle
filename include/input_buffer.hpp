#ifndef INPUT_BUFFER_HPP
#define INPUT_BUFFER_HPP

#include <string>

class InputBuffer
{
private:
    std::string command;
    int historyLength = 0;

public:
    void setCommand(const std::string& input);
    std::string getCommand() const;
    int getHistoryLength() const;
};

#endif
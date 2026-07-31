#include <iostream>
#include "input_buffer.hpp"

int main()
{
    std::cout<<"Chronicle running.. hurray!!!\n";
    InputBuffer buffer;
    buffer.setCommand("Hello ironhold!!");
    std::cout<<buffer.getCommand()<<"\n";
    return 0;
}
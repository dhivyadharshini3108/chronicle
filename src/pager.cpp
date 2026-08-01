#include "pager.hpp"
#include <iostream>

Pager::Pager(const std::string& filename)
{
    this->filename = filename;

    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);

    if(!file.is_open())
    {
        std::ofstream createFile(filename, std::ios::binary);
        createFile.close();

        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    }
}

void Pager::close()
{
    if(file.is_open())
    {
        file.close();
    }
}
#ifndef PAGER_HPP
#define PAGER_HPP

#include <fstream>
#include <string>

constexpr unsigned int PAGE_SIZE = 4096;
constexpr unsigned int ENTITIES_PER_PAGE = 14;
constexpr unsigned int MAX_PAGES = 100;
constexpr unsigned int MAX_ENTITIES = ENTITIES_PER_PAGE * MAX_PAGES;

class Pager
{
private:
    std::fstream file;
    std::string filename;

public:
    Pager(const std::string& filename);

    void close();
};

#endif
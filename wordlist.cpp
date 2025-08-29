#include <format>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "wordlist.h"

Wordlist::Wordlist(std::string_view filename)
{
    std::ifstream input(std::string{filename});

    if (!input)
    {
        throw std::runtime_error(std::format("Cannot open {} for reading.", filename));
    }

    std::string line;

    while (std::getline(input, line))
    {
        words_.push_back(line);
    }
}

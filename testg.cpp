#include <iostream>
#include <string>

#include "ansi.h"
#include "gallows.h"

int main()
{
    TextGallows gallows{};

    std::cout << ANSI::clear;

    for (std::size_t i = 0; i < gallows.stages(); ++i)
    {
        gallows.show();
        std::string ch;
        std::getline(std::cin, ch);

        gallows.next();
    }
}

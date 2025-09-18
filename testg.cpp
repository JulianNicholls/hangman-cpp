#include <iostream>
#include <string>

#include "ansi.h"
#include "gallows.h"

int main()
{
    TextGallows gallows{};

    std::cout << ANSI::clear;

    for (int i = 0; i < 4; ++i)
    {
        gallows.show();
        std::string ch;
        std::getline(std::cin, ch);

        gallows.next();
    }
}

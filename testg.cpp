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

        ANSI::move_cursor(25, 1);
        std::cin.get();

        gallows.next();
    }
}

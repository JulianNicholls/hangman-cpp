#include <iostream>
#include <print>
#include <string>

#include "ansi.h"
#include "gallows.h"

int main()
{
    TextGallows gallows{};

    std::print(ANSI::clear);

    for (unsigned int i = 0; i < 16; ++i)
    {
        for (unsigned int j = 0; j < 16; ++j)
        {
            const unsigned int index = i * 16 + j;
            std::print("{}{}{:>3}", ANSI::move_cursor(27 + i, j * 5 + 1), ANSI::colour256(index), index);
        }
    }

    for (std::size_t i = 0; i < gallows.stages(); ++i)
    {
        gallows.draw();

        std::print("{}", ANSI::move_cursor(25, 1));
        std::cin.get();

        gallows.next();
    }
}

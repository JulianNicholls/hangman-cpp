#include <format>
#include <iostream>

namespace ANSI
{
// Move to line and column (1-based)
void move_cursor(unsigned int line, unsigned int column)
{
    std::cout << std::format("\x1b[{};{}f", line, column);
}
}

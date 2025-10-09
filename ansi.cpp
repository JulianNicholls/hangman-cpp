#include <format>
#include <iostream>

namespace ANSI
{
// Move to line and column (1-based)
constexpr std::string move_cursor(unsigned int line, unsigned int column)
{
    return std::format("\x1b[{};{}H", line, column);
}

constexpr std::string colour256(unsigned int index)
{
    // Return a 256-colour colour
    return std::format("\x1b[38;5;{}m", index);
}
}

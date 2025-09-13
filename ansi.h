#ifndef ANSI_H
#define ANSI_H

#include <format>
#include <iostream>
#include <string>

namespace ANSI
{
constexpr std::string clear = "\e[2J";
constexpr std::string home = "\e[;H";

constexpr std::string reset = "\x1b[0m";

constexpr std::string bg_red = "\x1b[0;41m";
constexpr std::string bg_green = "\x1b[0;42m";
constexpr std::string bg_brown = "\x1b[0;43m";
constexpr std::string bg_blue = "\x1b[0;44m";
constexpr std::string bg_magenta = "\x1b[0;45m";
constexpr std::string bg_cyan = "\x1b[0;46m";
constexpr std::string bg_grey = "\x1b[0;47m";

constexpr std::string dark_red = "\x1b[0;31m";
constexpr std::string light_red = "\x1b[31;1m";
constexpr std::string dark_green = "\x1b[0;32m";
constexpr std::string light_green = "\x1b[32;1m";
constexpr std::string brown = "\x1b[0;33m";
constexpr std::string yellow = "\x1b[33;1m";
constexpr std::string dark_blue = "\x1b[0;34m";
constexpr std::string light_blue = "\x1b[34;1m";
constexpr std::string dark_magenta = "\x1b[0;35m";
constexpr std::string light_magenta = "\x1b[35;1m";
constexpr std::string dark_cyan = "\x1b[0;36m";
constexpr std::string light_cyan = "\x1b[36;1m";
constexpr std::string grey = "\x1b[0;37m";
constexpr std::string white = "\x1b[37;1m";

constexpr void move_cursor(int line, int column)
{
    std::cout << std::format("\x1b[{};{}H", line, column);
}
};

#endif // ANSI_H

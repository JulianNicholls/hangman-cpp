#ifndef ANSI_H
#define ANSI_H

#include <string>

namespace ANSI
{
const std::string clear = "\e[2J";
const std::string home = "\e[;H";

const std::string reset = "\x1b[0m";

const std::string bg_red = "\x1b[0;41m";
const std::string bg_green = "\x1b[0;42m";
const std::string bg_brown = "\x1b[0;43m";
const std::string bg_blue = "\x1b[0;44m";
const std::string bg_magenta = "\x1b[0;45m";
const std::string bg_cyan = "\x1b[0;46m";
const std::string bg_grey = "\x1b[0;47m";

const std::string dark_red = "\x1b[0;31m";
const std::string light_red = "\x1b[31;1m";
const std::string dark_green = "\x1b[0;32m";
const std::string light_green = "\x1b[32;1m";
const std::string brown = "\x1b[0;33m";
const std::string yellow = "\x1b[33;1m";
const std::string dark_blue = "\x1b[0;34m";
const std::string light_blue = "\x1b[34;1m";
const std::string dark_magenta = "\x1b[0;35m";
const std::string light_magenta = "\x1b[35;1m";
const std::string dark_cyan = "\x1b[0;36m";
const std::string light_cyan = "\x1b[36;1m";
const std::string grey = "\x1b[0;37m";
const std::string white = "\x1b[37;1m";

void move_cursor(unsigned int line, unsigned int column);
}

#endif // ANSI_H

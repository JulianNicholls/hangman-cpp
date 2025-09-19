#include <sstream>

#include "ansi.h"
#include "gallows.h"

using namespace ANSI;

const std::string land = "";
const std::string top = "";

const std::vector<GallowsEntry> TextGallows::gallows_entries_ = {
    {.line = 24, .column = 1, .text = brown + "------------------------------------"},
    {.line = 2, .column = 2, .text = brown + "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"},
    {.line = 1, .column = 3, .text = brown + "-----------------------"},
    {.line = 2, .column = 3, .text = brown + " /\n/"},
    {.line = 2, .column = 24, .text = brown + "|\n|"},
    {.line = 4,
     .column = 21,
     .text =
         yellow + " -----\n| " + light_blue + "o o" + yellow + " |\n|  " + light_blue + "o" + yellow + "  |\n -----"},
    {.line = 8,
     .column = 18,
     .text = yellow + " ____|_|____\n|           |\n|     " + light_green + "O" + yellow + "     |\n|     " +
             light_green + "O" + yellow + "     |\n|     " + light_green + "O" + yellow +
             "     |\n|           |\n -----------"},

};

void TextGallows::show() const
{
    const auto &entry = gallows_entries_[index_];
    std::istringstream lines{entry.text};
    unsigned int line = entry.line;
    std::string str;

    while (std::getline(lines, str))
    {
        ANSI::move_cursor(line++, entry.column);
        std::cout << str;
    }
}

const std::vector<std::string> previous = {

    brown + top + " | /   " + yellow + "|" + brown + "\n |/              |" + yellow + "|" + brown +
        "\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ \n |          /  _|           "
        "|\n |         /  / |     O     |\n |        /  /  |     O     |\n |       -----  |     O     |\n |       "
        "|___|  |     O     |\n |       |_|_|  |           |\n |               -----------\n |\n |\n |\n |\n |\n "
        "|\n |\n |" +
        land,
    brown + top + " | /   " + yellow + "|" + brown + "\n |/              |" + yellow + "|" + brown +
        "\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |\n |\n |\n |\n |\n |\n |\n |" +
        land,
    brown + top + " | /   " + yellow + "|" + brown + "\n |/              |" + yellow + "|" + brown +
        "\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |               |  |\n |               |  |\n |               |  |\n |               |  |\n |   "
        "           /  /\n |              ---\n |\n |" +
        land,
    brown + top + " | /   " + yellow + "|" + brown + "\n |/              |" + yellow + "|" + brown +
        "\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |               |  |   |  |\n |               |  |   |  |\n |               |  |   |  |\n |     "
        "          |  |   |  |\n |              /  /   /  /\n |              ---    ---\n |\n |" +
        land};

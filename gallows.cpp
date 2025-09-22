#include <sstream>

#include "ansi.h"
#include "gallows.h"

using namespace ANSI;

const std::string leg = " |  |\n |  |\n |  |\n |  |\n/  /\n---";

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
             light_green + "O" + yellow + "     |\n|     " + light_green + "O" + yellow + "     |\n|     " +
             light_green + "O" + yellow + "     |\n|           |\n -----------"},
    {.line = 8, .column = 11, .text = yellow + "    ___\n   /  _\n  /  /\n /  /\n-----\n|___|\n|_|_|"},
    {.line = 8, .column = 31, .text = yellow + "___\n_  \\\n \\  \\\n  \\  \\\n  -----\n  |___|\n  |_|_|"},
    {.line = 16, .column = 18, .text = yellow + leg},
    {.line = 16, .column = 25, .text = yellow + leg},

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

void TextGallows::draw_state() const
{
    for (size_t i = 0; i <= index_; ++i)
    {
        const auto &entry = gallows_entries_[i];
        std::istringstream lines{entry.text};
        unsigned int line = entry.line;
        std::string str;

        while (std::getline(lines, str))
        {
            ANSI::move_cursor(line++, entry.column);
            std::cout << str;
        }
    }
}

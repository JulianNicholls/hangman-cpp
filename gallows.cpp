#include "gallows.h"
#include "ansi.h"

using namespace ANSI;

constexpr char *leg = " |  |\n |  |\n |  |\n |  |\n/  /\n---";

const std::vector<GallowsEntry> TextGallows::gallows_entries_ = {
    {24, 1, brown + "------------------------------------"},
    {2, 2, brown + "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"},
    {1, 3, brown + "-----------------------"},
    {2, 3, brown + " /\n/"},
    {2, 24, brown + "|\n|"},
    {4,
     21,
     yellow + " -----\n| " + light_blue + "o o" + yellow + " |\n|  " + light_blue + "o" + yellow + "  |\n -----"},
    {8,
     18,
     yellow + " ____|_|____\n|           |\n|     " + light_green + "O" + yellow + "     |\n|     " + light_green +
         "O" + yellow + "     |\n|     " + light_green + "O" + yellow + "     |\n|     " + light_green + "O" + yellow +
         "     |\n|           |\n -----------"},
    {8, 11, yellow + "    ___\n   /  _\n  /  /\n /  /\n-----\n|___|\n|_|_|"},
    {8, 31, yellow + "___\n_  \\\n \\  \\\n  \\  \\\n  -----\n  |___|\n  |_|_|"},
    {16, 18, yellow + leg},
    {16, 25, yellow + leg},

};

#include <array>

#include "ansi.h"
#include "gallows.h"

const char *leg = " |  |\n |  |\n |  |\n |  |\n/  /\n---";
const std::string brown = ANSI::colour256(94);
const std::string yellow = ANSI::colour256(226);
const std::string light_blue = ANSI::colour256(33);
const std::string light_green = ANSI::colour256(154);

const std::array<GallowsEntry, 11> TextGallows::gallows_entries_ = {
    GallowsEntry{24, 1, brown + "------------------------------------"},
    GallowsEntry{2, 2, brown + "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"},
    GallowsEntry{1, 3, brown + "-----------------------"},
    GallowsEntry{2, 3, brown + " /\n/"},
    GallowsEntry{2, 24, brown + "|\n|"},
    GallowsEntry{
        4,
        21,
        yellow + " -----\n| " + light_blue + "o o" + yellow + " |\n|  " + light_blue + "o" + yellow + "  |\n -----"},
    GallowsEntry{
        8,
        18,
        yellow + " ____|_|____\n|           |\n|     " + light_green + "O" + yellow + "     |\n|     " + light_green +
            "O" + yellow + "     |\n|     " + light_green + "O" + yellow + "     |\n|     " + light_green + "O" +
            yellow + "     |\n|           |\n -----------"},
    GallowsEntry{8, 11, yellow + "    ___\n   /  _\n  /  /\n /  /\n-----\n|___|\n|_|_|"},
    GallowsEntry{8, 31, yellow + "___\n_  \\\n \\  \\\n  \\  \\\n  -----\n  |___|\n  |_|_|"},
    GallowsEntry{16, 18, yellow + leg},
    GallowsEntry{16, 25, yellow + leg},

};

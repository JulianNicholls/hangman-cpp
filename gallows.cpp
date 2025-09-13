#include "gallows.h"
#include "ansi.h"

using namespace ANSI;

const std::string top_with_rope =
    brown + top + " | /                  " + yellow + "|" + brown + "\n |/                   " + yellow + "|" + brown;

const std::string top_with_head = top_with_rope + "\n |                  " + yellow + "-----" + brown +
                                  "\n |                 " + yellow + "| o o |" + brown +
                                  "\n |   "
                                  "              " +
                                  yellow + "|  o  |" + brown + "\n |                  " + yellow + "-----" + brown;

const std::vector<std::string> TextGallows::gallows_text = {
    brown + "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" + land,
    brown + "\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    brown + top + " |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    brown + top + " | /\n |/\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    top_with_rope + "\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    top_with_head +
        "\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n "
        "|\n |\n |" +
        land,

    top_with_head + "\n |               " + yellow + "____|_|____" + brown + "\n |              " + yellow +
        "|           |" + brown + "\n |              " + yellow + "|     " + light_green + "O" + yellow + "     |" +
        brown + "\n |              " + yellow + "|     " + light_green + "O" + yellow + "     |" + brown +
        "\n |              " + yellow + "|     " + light_green + "O" + yellow + "     |" + brown +
        "\n |            "
        "  " +
        yellow + "|     " + light_green + "O" + yellow + "     |" + brown + "\n |              " + yellow +
        "|           |" + brown + "\n |               " + yellow + "-----------\n" + brown +
        " |\n |\n |\n |\n |\n |\n "
        "|\n |" +
        land,

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

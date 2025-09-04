#include <format>
#include <iostream>

#include "word.h"
#include "wordlist.h"

namespace
{
const char *clear = "\e[2J";
const char *home = "\e[;H";

// constexpr std::string land = "------------\n";
// constexpr std::string top = " --------\n";

const std::string land = "------------------------------------\n";
const std::string top = " -----------------------\n";

const std::vector<std::string> old_gallows = {
    "\n\n\n\n\n\n" + land,
    "\n |\n |\n |\n |\n |\n" + land,
    top + " |\n |\n |\n |\n |\n" + land,
    top + " |/\n |\n |\n |\n |\n" + land,
    top + " |/     |\n |\n |\n |\n |\n" + land,
    top + " |/     |\n |      o\n |\n |\n |\n" + land,
    top + " |/     |\n |      o\n |      O\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |     /\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |     / \\ \n |\n" + land};
}

const std::vector<std::string> gallows = {
    "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" + land,
    "\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    top + " |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    top + " | /\n |/\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |" + land,
    top +
        " | /                  |\n |/                   |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n "
        "|\n |\n |\n |\n |\n |\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n "
        "|\n |\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |               ____|_|____ \n |              |           "
        "|\n |              |     O     |\n |              |     O     |\n |              |     O     |\n |            "
        "  |     O     |\n |              |           |\n |               -----------\n |\n |\n |\n |\n |\n |\n |\n "
        "|\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ \n |          /  _|           "
        "|\n |         /  / |     O     |\n |        /  /  |     O     |\n |       -----  |     O     |\n |       "
        "|___|  |     O     |\n |       |_|_|  |           |\n |               -----------\n |\n |\n |\n |\n |\n |\n "
        "|\n |\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |\n |\n |\n |\n |\n |\n |\n |\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |               |  |\n |               |  |\n |               |  |\n |               |  |\n |   "
        "           /  /\n |              ---\n |\n |\n |" +
        land,
    top +
        " | /                  |\n |/                   |\n |                  -----\n |                 | o o |\n |   "
        "              |  o  |\n |                  -----\n |           ___ ____|_|____ ___\n |          /  _|         "
        "  |_  \\\n |         /  / |     O     | \\  \\\n |        /  /  |     O     |  \\  \\\n |       -----  |     "
        "O     |  -----\n |       |___|  |     O     |  |___|\n |       |_|_|  |           |  |_|_|\n |               "
        "-----------\n |               |  |   |  |\n |               |  |   |  |\n |               |  |   |  |\n |     "
        "          |  |   |  |\n |              /  /   /  /\n |              ---    ---\n |\n |\n |" +
        land};

std::string bad_guesses(const std::vector<char> &list)
{
    std::string out{"Guesses: "};

    for (char ch : list)
    {
        out += std::format("{} ", static_cast<char>(toupper(ch)));
    }

    return out + "\n";
}

void clear_screen()
{
    std::cout << clear << home;
}

void show_gallows(std::size_t stage)
{
    std::cout << gallows[stage];
}

int main()
{
    Wordlist words("words-2019.txt");

    std::cout << "Hangman V1.0\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    const std::string temp = words.random();
    Word choice(temp);

    char ch{' '};
    bool complete = false;

    auto hanged = [&choice]() { return choice.bad_letters.size() == gallows.size() - 1; };

    do
    {
        clear_screen();
        show_gallows(choice.bad_letters.size());

        std::cout << std::format("\n{}\n{}\n\n=> ", bad_guesses(choice.bad_letters), choice);

        std::cin >> ch;
        std::cin.ignore(100, '\n');

        if (!choice.guessed(ch))
        {
            choice.guess(ch);
        }

        complete = choice.done() || hanged() || ch == '\\';
    } while (!complete);

    if (choice.done())
    {
        std::cout << std::format("You got it: {}\n", choice.word);
    }
    else if (hanged())
    {
        clear_screen();
        show_gallows(choice.bad_letters.size());
        std::cout << std::format("\nBad luck! It was {}\n", choice.word);
    }
}

#include <format>
#include <iostream>

#include "word.h"
#include "wordlist.h"

namespace
{
const char *clear = "\e[2J";
const char *home = "\e[;H";

constexpr std::string land = "------------\n";
constexpr std::string top = " --------\n";

const std::vector<std::string> gallows = {
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

std::string bad_guesses(const std::vector<char> &list)
{
    std::string out{"Guesses: "};

    for (char ch : list)
    {
        out += std::format("{} ", static_cast<char>(toupper(ch)));
    }

    return out + "\n";
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

    auto hanged = [choice]() { return choice.bad_letters.size() == gallows.size() - 1; };

    do
    {
        std::cout << std::format(
            "{}{}{}\n{}\n{}\n=> ",
            clear,
            home,
            gallows[choice.bad_letters.size()],
            bad_guesses(choice.bad_letters),
            choice);
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
        std::cout << std::format("Bad luck! It was {}\n", choice.word);
    }
}

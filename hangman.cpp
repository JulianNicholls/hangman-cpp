#include <format>
#include <iostream>

#include "word.h"
#include "wordlist.h"

namespace
{
const char *clear = "\e[2J";
const char *home = "\e[;H";

const std::string land = "------------\n";
const std::string top = " --------\n";

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
    Word word(temp);
    std::cout << std::format("\n{}: {}\n\n", temp, word);

    char ch{' '};

    do
    {
        std::cout << std::format(
            "{}{}{}{}\n{} ", clear, home, gallows[word.bad_letters.size()], bad_guesses(word.bad_letters), word);
        std::cin >> ch;

        std::cin.ignore(100, '\n');

        if (!word.guessed(ch))
        {
            word.guess(ch);
        }

    } while (!word.done() && ch != '\\');
}

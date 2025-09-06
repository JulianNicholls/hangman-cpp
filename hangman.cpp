#include <format>
#include <iostream>

#include "gallows.h"
#include "word.h"
#include "wordlist.h"

namespace
{
const char *clear = "\e[2J";
const char *home = "\e[;H";
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

void clear_screen()
{
    std::cout << clear << home;
}

int main()
{
    Wordlist words("words-2019.txt");
    TextGallows gallows{};

    std::cout << "Hangman V1.0\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    const std::string temp = words.random();
    Word choice(temp);

    char ch{' '};
    bool complete = false;

    auto hanged = [&]() { return choice.bad_letters.size() == gallows.stages() - 1; };

    do
    {
        clear_screen();

        std::cout << std::format("{}\n\n{}\n{}\n\n=> ", gallows, bad_guesses(choice.bad_letters), choice);

        std::cin >> ch;
        std::cin.ignore(100, '\n');

        if (!choice.guessed(ch) && !choice.guess(ch))
            gallows.next();

        complete = choice.done() || hanged() || ch == '\\';
    } while (!complete);

    if (choice.done())
    {
        std::cout << std::format("You got it: {}\n", choice.word);
    }
    else if (hanged())
    {
        clear_screen();
        std::cout << std::format("{}\n\nBad luck! It was {}\n", gallows, choice.word);
    }
}

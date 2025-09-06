#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>

#include "gallows.h"
#include "word.h"
#include "wordlist.h"

namespace
{
const char *clear = "\e[2J";
const char *home = "\e[;H";

std::string upper(std::string_view text)
{
    std::string output{};

    std::ranges::transform(text, std::back_inserter(output), toupper);

    return output;
}
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
    std::cout << clear;
}

void cursor_home()
{
    std::cout << home;
}

int main()
{
    Wordlist words("words-2019.txt");
    TextGallows gallows{};

    std::cout << "Hangman V1.0\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    Word choice{};

    char ch{' '};
    bool complete = false;

    auto hanged = [&]() { return choice.bad_letters.size() == gallows.stages() - 1; };

    bool still_playing = true;

    while (still_playing)
    {
        clear_screen();

        const std::string temp = words.random();
        choice = temp;
        gallows.reset();

        do
        {
            cursor_home();

            std::cout << std::format("{}\n\n{}\n{}\n\n=> ", gallows, bad_guesses(choice.bad_letters), choice);

            std::cin >> ch;
            std::cin.ignore(100, '\n');

            ch = tolower(ch);

            if (!choice.guessed(ch) && !choice.guess(ch))
                gallows.next();

            complete = choice.done() || hanged() || ch == '\\';
        } while (!complete);

        clear_screen();
        cursor_home();

        if (choice.done())
        {
            std::cout << std::format("{}\nYou got it: {}\n", gallows, upper(choice.word));
        }
        else if (hanged())
        {
            std::cout << std::format("{}\nBad luck! It was {}\n", gallows, upper(choice.word));
        }

        std::cout << "\nplay again? ";
        std::cin >> ch;

        if (static_cast<char>(tolower(ch)) == 'n')
            still_playing = false;
    }
}

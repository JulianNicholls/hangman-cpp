#include <algorithm>
#include <chrono>
#include <format>
#include <iostream>
#include <ranges>
#include <thread>

#include <termios.h>
#include <unistd.h>

#include "gallows.h"
#include "word.h"
#include "wordlist.h"

using namespace std::chrono_literals;

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

// Get a character from the keyboard without requiring enter afterward.
#ifdef _WIN32
#include <conio.h>
char getchar_immediate()
{
    return _getch();
}
#else
char getchar_immediate()
{
    struct termios oldterm, newterm;
    char ch;

    tcgetattr(STDIN_FILENO, &oldterm);
    newterm = oldterm;

    newterm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newterm);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);

    return ch;
}
#endif

int main()
{
    Wordlist words("words-2019.txt");
    TextGallows gallows{};

    std::cout << "Hangman V1.03\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    std::this_thread::sleep_for(1s);

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

            ch = getchar_immediate();

            if (!choice.guessed(ch) && !choice.guess(ch))
                gallows.next();

            complete = choice.done() || hanged() || ch == '\\';
        } while (!complete);

        clear_screen();
        cursor_home();

        if (choice.done())
        {
            std::cout << std::format("{}{}\nYou got it: {}{}\n", gallows, light_green, upper(choice.word), reset);
        }
        else if (hanged())
        {
            std::cout << std::format("{}{}\nBad luck! It was {}{}\n", gallows, light_red, upper(choice.word), reset);
        }

        std::cout << light_blue + "\nplay again? " + reset;
        ch = getchar_immediate();

        if (static_cast<char>(tolower(ch)) == 'n')
            still_playing = false;
    }

    std::cout << std::endl;
}

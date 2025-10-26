#include <algorithm>
#include <chrono>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <thread>

#include <termios.h>
#include <unistd.h>

#include "ansi.h"
#include "gallows.h"
#include "word.h"
#include "wordlist.h"

using namespace std::chrono_literals;

namespace
{

std::string upper(std::string_view text)
{
    std::string output{};

    std::ranges::transform(text, std::back_inserter(output), toupper);

    return output;
}
}

std::string bad_guesses(const std::vector<char> &list)
{
    std::string out{ANSI::reset + "Guesses: " + ANSI::light_red};

    for (char ch : list)
    {
        out += std::format("{} ", static_cast<char>(toupper(ch)));
    }

    return out + "\n";
}

void clear_screen()
{
    std::cout << ANSI::clear;
}

void cursor_home()
{
    std::cout << ANSI::home;
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

int main(int argc, char *argv[])
{
    const std::string::size_type min_length = (argc > 1) ? atoi(argv[1]) : 5;

    Wordlist words("../assets/words-2025-5-16.txt");
    TextGallows gallows{};

    std::cout << "Hangman V1.04\n\n";
    std::cout << std::format("Words: {}\n", words.size());

    std::cout << std::format("\nMinimum length: {}\n", min_length);

    std::this_thread::sleep_for(1.5s);

    Word choice{};

    char ch{' '};
    bool complete = false;

    auto hanged = [&]() { return choice.bad_letters.size() == gallows.stages() - 1; };

    bool still_playing = true;

    while (still_playing)
    {
        clear_screen();

        choice = words.random(min_length);
        gallows.reset();

        do
        {
            gallows.draw();
            std::cout << ANSI::move_cursor(26, 1)
                      << std::format("{}\n{}{}\n\n=> ", bad_guesses(choice.bad_letters), ANSI::reset, choice);

            ch = getchar_immediate();

            if (isalpha(ch) && !choice.guessed(ch) && !choice.guess(ch))
                gallows.next();

            complete = choice.done() || hanged() || ch == '\\';
        } while (!complete);

        clear_screen();

        if (choice.done())
        {
            gallows.draw_state();
            std::cout << ANSI::move_cursor(26, 1)
                      << std::format("{}\nYou got it: {}{}\n", ANSI::light_green, upper(choice.word), ANSI::reset);
        }
        else if (hanged())
        {
            gallows.draw_state();
            std::cout << ANSI::move_cursor(26, 1)
                      << std::format("{}\nBad luck! It was {}{}\n", ANSI::light_red, upper(choice.word), ANSI::reset);
        }

        std::cout << ANSI::light_blue + "\nplay again? " + ANSI::reset;
        ch = getchar_immediate();

        if (static_cast<char>(tolower(ch)) == 'n')
            still_playing = false;
    }

    std::cout << std::endl;
}

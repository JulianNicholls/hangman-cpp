#include <algorithm>
#include <chrono>
#include <format>
#include <print>
#include <ranges>
#include <string>
#include <thread>

#include <termios.h>
#include <unistd.h>

#include "ansi.h"
#include "config.h"
#include "text_gallows.h"
#include "word.h"
#include "wordlist.h"

using namespace std::chrono_literals;

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
    std::print(ANSI::clear);
}

void cursor_home()
{
    std::print(ANSI::home);
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
    Config config{"hangman.cfg"};
    const size_t min_length = stoi(config.at("min_word_length"));

    Wordlist words("../assets/words-2025-5-16.txt");
    TextGallows gallows{};

    std::println("Hangman V1.05\n");
    std::println("Words: {}", words.size());
    std::println("\nMinimum length: {}", min_length);

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
            std::print(
                "{}{}\n{}{}\n\n=> ", ANSI::move_cursor(26, 1), bad_guesses(choice.bad_letters), ANSI::reset, choice);

            ch = getchar_immediate();

            if (isalpha(ch) && !choice.guessed(ch) && !choice.guess(ch))
                gallows.next();

            complete = choice.done() || hanged() || ch == '\\';
        } while (!complete);

        clear_screen();

        if (choice.done())
        {
            gallows.draw_state();
            std::println(
                "{}{}\nYou got it: {}{}", ANSI::move_cursor(26, 1), ANSI::light_green, choice.display(), ANSI::reset);
        }
        else if (hanged())
        {
            gallows.draw_state();
            std::println(
                "{}{}\nBad luck! It was {}{}",
                ANSI::move_cursor(26, 1),
                ANSI::light_red,
                choice.display(),
                ANSI::reset);
        }

        std::print("\n{}play again? {}", ANSI::light_blue, ANSI::reset);
        ch = getchar_immediate();

        if (static_cast<char>(tolower(ch)) == 'n')
            still_playing = false;
    }

    std::println();
}

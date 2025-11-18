#include <print>
#include <string>

#include <termios.h>
#include <unistd.h>

#include "ansi.h"
#include "text_gallows.h"
#include "text_game.h"
#include "word.h"
#include "wordlist.h"

namespace
{

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

}

Game::Game(size_t min_length)
    : words_{"../assets/words-2025-5-16.txt"}
    , gallows_{}
    , state_{GameState::PLAYING}
    , min_length_{min_length}
    , word_{}
{
}

void Game::run()
{
    while (state_ != GameState::COMPLETE)
    {
        clear_screen();

        word_ = words_.random(min_length_);
        gallows_.reset();

        do
        {
            drawPlaying();
            updatePlaying();
        } while (state_ == GameState::PLAYING);

        clear_screen();

        if (state_ == GameState::SUCCESS)
        {
            drawSuccess();
        }
        else
        {
            drawFailure();
        }

        drawEnding();
        updateEnding();
    }
}

void Game::updatePlaying()
{
    auto ch = getchar_immediate();

    if (isalpha(ch) && !word_.guessed(ch) && !word_.guess(ch))
        gallows_.next();

    if (word_.done())
    {
        state_ = GameState::SUCCESS;
    }
    else if (word_.bad_letters.size() == gallows_.stages() - 1)
    {
        state_ = GameState::FAILURE;
    }
}

void Game::updateEnding()
{
    char ch = getchar_immediate();

    if (static_cast<char>(tolower(ch)) == 'n')
        state_ = GameState::COMPLETE;
}

void Game::drawPlaying() const
{
    gallows_.draw();
    std::print("{}{}\n{}{}\n\n=> ", ANSI::move_cursor(26, 1), bad_guesses(word_.bad_letters), ANSI::reset, word_);
}

void Game::drawSuccess() const
{
    gallows_.draw_state();
    std::println("{}{}\nYou got it: {}{}", ANSI::move_cursor(26, 1), ANSI::light_green, word_.display(), ANSI::reset);
}

void Game::drawFailure() const
{
    gallows_.draw_state();
    std::println(
        "{}{}\nBad luck! It was {}{}", ANSI::move_cursor(26, 1), ANSI::light_red, word_.display(), ANSI::reset);
}

void Game::drawEnding() const
{
    std::print("\n{}play again? {}", ANSI::light_blue, ANSI::reset);
}

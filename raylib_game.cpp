#include "raylib.h"

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "raylib_game.h"
#include "word.h"

const std::unordered_map<GameState, void (Game::*)()> Game::updates_ = {
    {GameState::STARTING, &Game::updateStarting},
    {GameState::PLAYING, &Game::updatePlaying},
    {GameState::SUCCESS, &Game::updateEnding},
    {GameState::FAILURE, &Game::updateEnding},
    {GameState::COMPLETE, &Game::updateNothing}};

const std::unordered_map<GameState, void (Game::*)() const> Game::draws_ = {
    {GameState::STARTING, &Game::drawStarting},
    {GameState::PLAYING, &Game::drawPlaying},
    {GameState::SUCCESS, &Game::drawEnding},
    {GameState::FAILURE, &Game::drawEnding},
    {GameState::COMPLETE, &Game::drawNothing}};

namespace
{
void centre(
    const Window &window,
    const ::Font &font,
    const std::string &text,
    float y,
    float size,
    float spacing,
    ::Color colour)
{
    auto textsize = ::MeasureTextEx(font, text.c_str(), size, spacing);

    ::DrawTextEx(font, text.c_str(), {window.width / 2.0f - textsize.x / 2.0f, y}, size, spacing, colour);
}
}

Game::Game(const Window &window, size_t min_length)
    : window_{window}
    , words_{"../assets/words-2025-5-16.txt"}
    , state_{GameState::STARTING}
    , word_{words_.random(min_length)}
    , gallows_{GraphicGallows{}}
    , font_{LoadFontEx("../assets/bloodcrow.ttf", 36, nullptr, 0)}
    , letter_grid_{LetterGrid{font_, 40, 780, 36, 40.0f}}
    , images_{ImageLoader{"../assets"}}
{
    ::SetTargetFPS(60);
    ::SetExitKey(0); // Disable Esc to exit
}

void Game::updateStarting()
{
    if (::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        state_ = GameState::PLAYING;
    }
}

void Game::updatePlaying()
{
    if (auto ch = letter_grid_.update(word_); ch != ' ')
    {
        if (!word_.guess(ch))
        {
            gallows_.next();
        }
    }

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
    if (::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        state_ = GameState::COMPLETE;
    }
}

void Game::drawStarting() const
{
    ::DrawTexture(images_.at("lets-go-600"), 0, 0, WHITE);
    say_click_to_continue();
}

void Game::drawPlaying() const
{
    gallows_.draw();
    show_guessed();
    letter_grid_.draw(word_);
    ::DrawTextEx(font_, std::format("{}", word_).c_str(), {40, 620}, 36, 0, SKYBLUE);
}

void Game::drawEnding() const
{
    auto info_text = std::format("The word was  {}", word_.display());

    centre(
        window_,
        font_,
        info_text,
        700,
        36,
        3,
        state_ == GameState::SUCCESS ? ::Color{120, 255, 120, 255} : ::Color{255, 50, 50, 255});
    ::DrawTexture(state_ == GameState::SUCCESS ? images_.at("success-600") : images_.at("failure-600"), 0, 0, WHITE);
    say_click_to_continue();
}

void Game::run()
{
    int idx = 0;

    auto hanged = [&]() { return; };

    while (!::WindowShouldClose() && state_ != GameState::COMPLETE)
    {
        (this->*(updates_.at(state_)))();

        ::BeginDrawing();

        ::ClearBackground(BLACK);

        (this->*(draws_.at(state_)))();

        ::EndDrawing();
    }
}

void Game::say_click_to_continue() const
{
    centre(window_, font_, "Click to Continue", 800, 36, 0, SKYBLUE);
}

void Game::show_guessed() const
{
    const auto bad = word_.bad_letters;

    if (bad.size() > 0)
    {
        ::DrawTextEx(font_, "Guesses:", {40, 700}, 36, 0, SKYBLUE);

        std::string out{};

        for (char ch : bad)
        {
            out += std::format("{} ", static_cast<char>(toupper(ch)));
        }

        ::DrawTextEx(font_, out.c_str(), {200, 700}, 36, 3, {255, 50, 50, 255});
    }
}

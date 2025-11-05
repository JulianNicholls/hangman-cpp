#include "raylib.h"

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "raylib_game.h"
#include "word.h"

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

    ::DrawTextEx(font, text.c_str(), {window.width / 2 - textsize.x / 2, y}, size, spacing, colour);
}
}

Game::Game(const Window &window, std::size_t min_length)
    : window_{window}
    , words_{"../assets/words-2025-5-16.txt"}
    , state_{GameState::STARTING}
    , word_{words_.random(min_length)}
    , gallows_{GraphicGallows{}}
    , font_{LoadFontEx("../assets/bloodcrow.ttf", 36, nullptr, 0)}
    , letter_grid_{LetterGrid{font_, 40, 780, 36, 40}}
    , images_{ImageLoader{"../assets"}}
{
    ::SetTargetFPS(60);
    ::SetExitKey(0); // Disable Esc to exit
}

void Game::update()
{
    const auto left_button_pressed = ::IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    switch (state_)
    {
        using enum GameState;

        case STARTING:
            if (left_button_pressed)
                state_ = PLAYING;
            break;

        case PLAYING:
            if (auto ch = letter_grid_.update(word_); ch != ' ')
            {
                if (!word_.guess(ch))
                    gallows_.next();
            }

            if (word_.done())
                state_ = SUCCESS;
            else if (word_.bad_letters.size() == gallows_.stages() - 1)
                state_ = FAILURE;
            break;

        case SUCCESS:
        case FAILURE:
            if (left_button_pressed)
                state_ = COMPLETE;
            break;

        case COMPLETE: break;
    }
}

void Game::run()
{
    int idx = 0;

    auto hanged = [&]() { return; };

    while (!::WindowShouldClose() && state_ != GameState::COMPLETE)
    {
        update();

        if (state_ != GameState::COMPLETE)
            ::BeginDrawing();

        ::ClearBackground(BLACK);

        switch (state_)
        {
            using enum GameState;

            case STARTING:
                gallows_.draw();
                ::DrawTexture(images_.at("lets-go-600"), 0, 0, WHITE);
                say_click_to_continue();
                break;

            case PLAYING:
                gallows_.draw();
                show_guessed();
                letter_grid_.draw(word_);
                ::DrawTextEx(font_, std::format("{}", word_).c_str(), {40, 620}, 36, 0, SKYBLUE);
                break;

            case SUCCESS:
            case FAILURE:
            {
                auto info_text = std::format("The word was  {}", word_.display());

                centre(
                    window_,
                    font_,
                    info_text,
                    700,
                    36,
                    3,
                    state_ == SUCCESS ? ::Color{120, 255, 120, 255} : ::Color{255, 50, 50, 255});
                ::DrawTexture(state_ == SUCCESS ? images_.at("success-600") : images_.at("failure-600"), 0, 0, WHITE);
                say_click_to_continue();
            }
            break;

            case COMPLETE: break;
        }

        if (state_ != GameState::COMPLETE)
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
        ::DrawTextEx(font_, "Guesses:", {40, 700}, 36, 3, SKYBLUE);

        std::string out{};

        for (char ch : bad)
        {
            out += std::format("{} ", static_cast<char>(toupper(ch)));
        }

        ::DrawTextEx(font_, out.c_str(), {200, 700}, 36, 3, {255, 50, 50, 255});
    }
}

#include "raylib.h"

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "raylib_game.h"
#include "word.h"

Game::Game(int width, int height, const std::string_view title)
    : words_{"../assets/words-2025-5-16.txt"}
    , gallows_{}
    , state_{GameState::STARTING}
    , word_{words_.random()}
{
    // This MUST be done before anything else raylib-related, not least loading texture images
    ::InitWindow(width, height, std::string{title}.c_str());
    ::SetTargetFPS(60);
    ::SetExitKey(0); // Disable Esc to exit

    gallows_ = std::make_unique<GraphicGallows>();
    font_ = std::make_unique<Font>(LoadFontEx("../assets/bloodcrow.ttf", 36, nullptr, 0));
    letter_grid_ = std::make_unique<LetterGrid>(*font_, 40, 780, 36, 40);
    images_ = std::make_unique<ImageLoader>("../assets");
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
            if (auto ch = letter_grid_->update(); ch != ' ')
            {
                if (!word_.guess(ch))
                    gallows_->next();
            }

            if (word_.done())
                state_ = SUCCESS;
            else if (word_.bad_letters.size() == gallows_->stages() - 1)
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
                gallows_->draw();
                ::DrawTexture(images_->at("lets-go-600"), 0, 0, WHITE);
                say_click_to_continue();
                break;

            case PLAYING:
                gallows_->draw();
                show_guessed();
                letter_grid_->draw(word_);
                ::DrawTextEx(*font_, std::format("{}", word_).c_str(), {40, 620}, 36, 0, SKYBLUE);
                break;

            case SUCCESS:
            case FAILURE:
                ::DrawTextEx(
                    *font_,
                    std::format("THE WORD WAS   {}", word_.display()).c_str(),
                    {40, 700},
                    36,
                    0,
                    state_ == SUCCESS ? ::Color{120, 255, 120, 255} : ::Color{255, 50, 50, 255});
                ::DrawTexture(state_ == SUCCESS ? images_->at("success-600") : images_->at("failure-600"), 0, 0, WHITE);
                say_click_to_continue();
                break;

            case COMPLETE: break;
        }

        if (state_ != GameState::COMPLETE)
            ::EndDrawing();
    }

    ::CloseWindow();
}

void Game::say_click_to_continue() const
{
    ::DrawTextEx(*font_, "CLICK TO CONTINUE", {140, 800}, 36, 0, SKYBLUE);
}

void Game::show_guessed() const
{
    const auto bad = word_.bad_letters;

    if (bad.size() > 0)
    {
        ::DrawTextEx(*font_, "Guesses:", {40, 700}, 36, 0, SKYBLUE);

        std::string out{};

        for (char ch : bad)
        {
            out += std::format("{} ", static_cast<char>(toupper(ch)));
        }

        ::DrawTextEx(*font_, out.c_str(), {200, 700}, 36, 0, {255, 50, 50, 255});
    }
}

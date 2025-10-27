#include "raylib.h"

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "raylib_game.h"
#include "word.h"

Game::Game(int width, int height, const std::string_view title)
    : words_{"../assets/words-2025-5-16.txt"}
    , gallows_{}
    , state_{GameState::PLAYING}
    , word_{words_.random()}
{
    // This MUST be done before anything else raylib-related, not least loading texture images
    InitWindow(width, height, std::string{title}.c_str());
    SetTargetFPS(60);
    SetExitKey(0); // Disable Esc to exit

    gallows_ = std::make_unique<GraphicGallows>();
    font_ = std::make_unique<Font>(LoadFontEx("../assets/bloodcrow.ttf", 36, nullptr, 0));
    letter_grid_ = std::make_unique<LetterGrid>(*font_, 40, 680, 36, 40);
    images_ = std::make_unique<ImageLoader>("../assets");
}

void Game::update()
{
    switch (state_)
    {
        using enum GameState;

        case STARTING:
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
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
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                state_ = COMPLETE;
            break;

        case COMPLETE: break;
    }
}

void Game::run()
{
    int idx = 0;

    auto hanged = [&]() { return; };

    while (!WindowShouldClose() && state_ != GameState::COMPLETE)
    {
        update();

        if (state_ != GameState::COMPLETE)
            BeginDrawing();

        ClearBackground(BLACK);

        switch (state_)
        {
            using enum GameState;

            case STARTING: DrawTexture(images_->at("lets-go"), 0, 300, WHITE); break;

            case PLAYING:
                gallows_->draw();
                letter_grid_->draw(word_);
                DrawTextEx(*font_, std::format("{}", word_).c_str(), {40, 620}, 36, 2, SKYBLUE);
                break;

            case SUCCESS: DrawTexture(images_->at("success-600"), 0, 300, WHITE); break;

            case FAILURE: DrawTexture(images_->at("failure-600"), 0, 300, WHITE); break;
            case COMPLETE: break;
        }

        if (state_ != GameState::COMPLETE)
            EndDrawing();
    }

    CloseWindow();
}

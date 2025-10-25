#include "raylib.h"

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "raylib_game.h"
#include "word.h"

Game::Game(int width, int height, const std::string_view title)
    : words_{"words-2025-5-16.txt"}
    , gallows_{}
{
    // This MUST be done before anything else, not least loading texture images
    InitWindow(width, height, std::string{title}.c_str());
    SetTargetFPS(60);

    gallows_ = std::make_unique<GraphicGallows>();
    font_ = std::make_unique<Font>(LoadFont("../assets/bloodcrow.ttf"));
    letter_grid_ = std::make_unique<LetterGrid>(*font_, 40, 680, 36, 40);
}

void Game::run()
{
    int idx = 0;

    Word word = words_.random();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if (auto ch = letter_grid_->update(); ch != ' ')
        {
            if (!word.guess(ch))
                gallows_->next();
        }

        //        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        //        {
        //            if (gallows_->stage() == 11)
        //            {
        //                gallows_->reset();
        //            }
        //            else
        //            {
        //                gallows_->next();
        //            }
        //        }

        gallows_->draw();
        letter_grid_->draw(word);

        DrawTextEx(*font_, std::format("{}", word).c_str(), {40, 620}, 36, 2, SKYBLUE);

        EndDrawing();
    }
}

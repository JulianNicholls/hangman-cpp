#include <format>

#include "raylib.h"

#include "graphic_gallows.h"
#include "raylib_game.h"

Game::Game(int width, int height, const std::string &title)
    : gallows_{}
{
    // This MUST be done before anything else, not least loading textures
    InitWindow(width, height, std::string{title}.c_str());

    gallows_ = std::make_unique<GraphicGallows>();

    SetTargetFPS(60);
}

void Game::run()
{
    int idx = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (gallows_->stage() == 11)
                gallows_->reset();
            else
                gallows_->next();
        }

        gallows_->draw();
        EndDrawing();
    }
}

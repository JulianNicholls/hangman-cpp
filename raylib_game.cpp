#include <format>

#include "raylib.h"

#include "images.h"
#include "raylib_game.h"

Game::Game(int width, int height, const std::string &title)
{
    // This MUST be done before anything else, not least loading textures
    InitWindow(width, height, std::string{title}.c_str());

    loadedImages_.load("../assets");

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
            idx = (idx + 1) % 12;
        }

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            idx = (12 + idx - 1) % 12;
        }

        const auto name = std::format("gal{}", idx);

        DrawTextureEx(loadedImages_.at(name), {0, 0}, 0, 2, WHITE);
        DrawText(name.c_str(), 10, 10, 24, DARKBLUE);

        EndDrawing();
    }
}

#include "raylib.h"

#include "raylib_game.h"

Game::Game(int width, int height, std::string_view title)
{
    InitWindow(width, height, std::string{title}.c_str());

    SetTargetFPS(60);
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hangman Minimal", 100, 100, 20, DARKGREEN);
        EndDrawing();
    }
}

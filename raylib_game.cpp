#include "raylib.h"

#include "images.h"
#include "raylib_game.h"

Game::Game(int width, int height, const std::string &title)
{
    // This MUST be done before anything else, not least loading the images
    InitWindow(width, height, std::string{title}.c_str());

    loadedImages_.load("../assets");

    SetTargetFPS(60);
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //        DrawText("Hangman Minimal", 10, 10, 40, DARKGREEN);

        DrawTexture(loadedImages_.at("gal0"), 0, 0, WHITE);
        EndDrawing();
    }
}

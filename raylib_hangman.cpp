#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    Game game{1920, 1080, "Hangman"};

    game.run();
}

#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    Game game{600, 900, "Hangman"};

    game.run();
}

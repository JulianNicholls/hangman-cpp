#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    Game game{300, 300, "Hangman"};

    game.run();
}

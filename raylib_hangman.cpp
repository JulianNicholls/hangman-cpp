#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    ::SetTraceLogLevel(LOG_WARNING);

    Game game{600, 900, "Hangman"};

    game.run();
}

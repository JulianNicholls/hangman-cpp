#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    const size_t min_length = (argc > 1) ? atoi(argv[1]) : 5;
    ::SetTraceLogLevel(LOG_WARNING);

    Game game{600, 900, "Hangman", min_length};

    game.run();
}

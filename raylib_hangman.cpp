#include "raylib.h"

#include "raylib_game.h"

int main(int argc, char **argv)
{
    const size_t min_length = (argc > 1) ? atoi(argv[1]) : 5;
    ::SetTraceLogLevel(LOG_WARNING);

    Window window{600, 900, "Hangman"};
    Game game{window, min_length};

    game.run();
}

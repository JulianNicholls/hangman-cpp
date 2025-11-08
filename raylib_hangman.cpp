#include "raylib.h"

#include "config.h"
#include "raylib_game.h"

int main()
{
    Config config("hangman.cfg");
    const size_t min_length = stoi(config.at("min_word_length"));

    ::SetTraceLogLevel(LOG_WARNING);

    Window window{600, 900, "Hangman"};
    Game game{window, min_length};

    game.run();
}

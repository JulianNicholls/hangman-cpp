#include <print>
#include <string>
#include <thread>

#include "config.h"
#include "text_game.h"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    Config config{"hangman.cfg"};
    const size_t min_length = stoi(config["min_word_length"]);

    std::println("Hangman V1.07\n\nMinimum length: {}", min_length);
    std::this_thread::sleep_for(2s);

    Game game{min_length};

    game.run();
    std::println();
}

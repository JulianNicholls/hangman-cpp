#ifndef RAYLIB_GAME
#define RAYLIB_GAME

#include <string>

class Game
{
  public:
    Game(int width, int height, std::string_view title);
    ~Game() = default;

    void run();
};

#endif // RAYLIB_GAME

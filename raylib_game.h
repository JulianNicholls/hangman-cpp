#ifndef RAYLIB_GAME
#define RAYLIB_GAME

#include <string>

#include "images.h"

class Game
{
  public:
    Game(int width, int height, const std::string &title);
    ~Game() = default;

    void run();

  private:
    ImageLoader loadedImages_{};
};

#endif // RAYLIB_GAME

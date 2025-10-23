#ifndef RAYLIB_GAME
#define RAYLIB_GAME

#include <string>

#include "graphic_gallows.h"

class Game
{
  public:
    Game(int width, int height, const std::string &title);
    ~Game() = default;

    void run();

  private:
    std::unique_ptr<GraphicGallows> gallows_;
};

#endif // RAYLIB_GAME

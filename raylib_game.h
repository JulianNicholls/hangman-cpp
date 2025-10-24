#ifndef RAYLIB_GAME_H
#define RAYLIB_GAME_H

#include <string>

#include "graphic_gallows.h"
#include "letter_grid.h"
#include "wordlist.h"

class Game
{
  public:
    Game(int width, int height, const std::string_view title);
    ~Game() = default;

    void run();

  private:
    Wordlist words_;
    std::unique_ptr<GraphicGallows> gallows_;
    std::unique_ptr<LetterGrid> letter_grid_;
};

#endif // RAYLIB_GAME_H

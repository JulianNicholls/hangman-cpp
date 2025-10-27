#ifndef RAYLIB_GAME_H
#define RAYLIB_GAME_H

#include <string_view>

#include "raylib.h"

#include "graphic_gallows.h"
#include "images.h"
#include "letter_grid.h"
#include "wordlist.h"

class Game
{
  public:
    Game(int width, int height, const std::string_view title);
    ~Game() = default;

    void run();
    const Font &font() const
    {
        return *font_;
    }

  private:
    enum struct GameState
    {
        STARTING,
        PLAYING,
        SUCCESS,
        FAILURE,
        COMPLETE
    };
    void update();

    GameState state_;
    Wordlist words_;
    Word word_;
    std::unique_ptr<GraphicGallows> gallows_;
    std::unique_ptr<LetterGrid> letter_grid_;
    std::unique_ptr<Font> font_;
    std::unique_ptr<ImageLoader> images_;
};

#endif // RAYLIB_GAME_H

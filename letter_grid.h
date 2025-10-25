#ifndef LETTER_GRID_H
#define LETTER_GRID_H

#include "word.h"

class Game;

class LetterGrid
{
  public:
    LetterGrid(const Game &game, int left, int top, int font_size = 16, int spacing = 24)
        : game_{game}
        , left_{left}
        , top_{top}
        , font_size_{font_size}
        , spacing_{spacing}
        , highlighted_(-1)
        , margin_{(spacing - font_size) / 2} {};

    char update();
    void draw(const Word &word) const;

  private:
    const Game &game_;

    int left_;
    int top_;
    int font_size_;
    int spacing_;
    int margin_;

    int highlighted_;
};
#endif // LETTER_GRID_H

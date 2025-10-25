#ifndef LETTER_GRID_H
#define LETTER_GRID_H

#include "raylib.h"

#include "word.h"

class LetterGrid
{
  public:
    LetterGrid(const Font &font, int left, int top, int font_size, int spacing)
        : font_{font}
        , left_{left}
        , top_{top}
        , font_size_{font_size}
        , spacing_{spacing}
        , margin_{(spacing - font_size) / 2}
        , highlighted_(-1) {};

    char update();
    void draw(const Word &word) const;

  private:
    const Font &font_;

    int left_;
    int top_;
    int font_size_;
    int spacing_;
    int margin_;

    int highlighted_;
};
#endif // LETTER_GRID_H

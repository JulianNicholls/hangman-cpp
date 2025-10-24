#ifndef LETTER_GRID_H
#define LETTER_GRID_H

#include "word.h"

class LetterGrid
{
  public:
    LetterGrid(int left, int top, int font_size = 16, int spacing = 24)
        : left_{left}
        , top_{top}
        , font_size_{font_size}
        , spacing_{spacing} {};

    void draw(const Word &word) const;

  private:
    int left_;
    int top_;
    int font_size_;
    int spacing_;
};
#endif // LETTER_GRID_H

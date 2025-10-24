#include "raylib.h"

#include "letter_grid.h"

void LetterGrid::draw(const Word &word) const
{
    DrawRectangle(left_, top_, spacing_, spacing_, WHITE);
}

#include "raylib.h"

#include "letter_grid.h"

void LetterGrid::draw(const Word &word) const
{
    char ltr[] = "A";

    for (int i = 0; i < 26; ++i)
    {
        ltr[0] = 'A' + i;
        const int line = i / 13;
        const int col = i % 13;
        DrawText(ltr, left_ + col * spacing_, top_ + line * spacing_, font_size_, WHITE);
    }
}

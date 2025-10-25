#include "raylib.h"

#include "letter_grid.h"
#include "raylib_game.h"

char LetterGrid::update()
{
    auto mouse_pos = GetMousePosition();

    if (mouse_pos.x < left_ || mouse_pos.x > left_ + 13 * spacing_ || mouse_pos.y < top_ ||
        mouse_pos.y > top_ + 2 * spacing_)
    {
        highlighted_ = -1;
        return ' ';
    }

    const int line = (mouse_pos.y - top_) / spacing_; // 0 or 1
    const int col = (mouse_pos.x - left_) / spacing_; // 0..12

    highlighted_ = line * 13 + col;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return 'a' + highlighted_;
    }

    return ' ';
}

void LetterGrid::draw(const Word &word) const
{
    char ltr[] = "A";

    for (int i = 0; i < 26; ++i)
    {
        ltr[0] = 'A' + i;

        if (word.guessed(ltr[0] | 0x20))
            continue;

        const int line = i / 13;
        const int col = i % 13;
        const float fSpacing = spacing_;
        if (i == highlighted_)
        {
            DrawRectangleRounded(
                {left_ + col * fSpacing, top_ + line * fSpacing, fSpacing, fSpacing}, 0.3f, 6, SKYBLUE);
        }

        // I'm not sure why the horizontal spacing needs an increase...
        DrawTextEx(
            font_, ltr, {left_ + margin_ * 2 + col * fSpacing, top_ + margin_ + line * fSpacing}, font_size_, 2, WHITE);
    }
}

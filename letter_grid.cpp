#include "raylib.h"

#include "letter_grid.h"

char LetterGrid::update(const Word &word)
{
    auto [x, y] = ::GetMousePosition();

    if (x < left_ || x > left_ + 13 * spacing_ || y < top_ || y > top_ + 2 * spacing_)
    {
        highlighted_ = -1;
        return ' ';
    }

    const int line = (y - top_) / spacing_; // 0 or 1
    const int col = (x - left_) / spacing_; // 0..12

    highlighted_ = line * 13 + col;
    const auto letter = 'a' + highlighted_;

    if (::IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !word.guessed(letter))
    {
        return letter;
    }

    return ' ';
}

void LetterGrid::draw(const Word &word) const
{
    char ltr[] = "A";

    for (unsigned int i = 0; i < 26; ++i)
    {
        ltr[0] = 'A' + i;

        if (word.guessed(static_cast<char>(tolower(ltr[0])))) // Lowercase for comparison
            continue;

        const int line = i / 13;
        const int col = i % 13;

        if (i == highlighted_)
        {
            ::DrawRectangleRounded(
                {left_ + col * spacing_, top_ + line * spacing_, spacing_, spacing_}, 0.3f, 6, SKYBLUE);
        }

        // I'm not sure why the horizontal spacing needs an increase.
        ::DrawTextEx(
            font_, ltr, {left_ + margin_ * 2 + col * spacing_, top_ + margin_ + line * spacing_}, font_size_, 0, WHITE);
    }
}

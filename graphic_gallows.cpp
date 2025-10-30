#include "raylib.h"

#include "graphic_gallows.h"

void GraphicGallows::draw() const
{
    const auto name = std::format("gal{}", index_);

    ::DrawText(name.c_str(), 10, 10, 24, DARKBLUE);
    ::DrawTextureEx(images_.at(name), {0, 0}, 0, 2, WHITE);
}

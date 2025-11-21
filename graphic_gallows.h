#ifndef GRAPHIC_GALLOWS_H
#define GRAPHIC_GALLOWS_H

#include <format>
#include <print>

#include "gallows.h"
#include "images.h"

class GraphicGallows : public Gallows
{
  public:
    GraphicGallows()
        : images_("../assets/gallows")
    {
    }

    std::size_t stages() const override
    {
        return images_.size();
    };

    void draw() const override
    {
        const auto name = std::format("gal{}", index_);
        // std::println("{}: {}", index_, name);

        ::DrawTextureEx(images_[name], {0, 0}, 0, 2, WHITE);
    }

    void draw_state() const override
    {
        draw();
    }

  private:
    ImageLoader images_;
};

#endif // GRAPHIC_GALLOWS_H

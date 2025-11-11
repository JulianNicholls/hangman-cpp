#ifndef GRAPHIC_GALLOWS_H
#define GRAPHIC_GALLOWS_H

#include <format>

#include "gallows.h"
#include "images.h"

class GraphicGallows : public Gallows
{
  public:
    GraphicGallows()
        : images_("../assets/gallows")
        , index_{0}
    {
    }

    std::size_t stages() const override
    {
        return images_.size();
    };

    void draw() const override
    {
        const auto name = std::format("gal{}", index_);

        ::DrawTextureEx(images_.at(name), {0, 0}, 0, 2, WHITE);
    }

    void draw_state() const override
    {
        draw();
    }

  private:
    ImageLoader images_;
    std::size_t index_{0};
};

#endif // GRAPHIC_GALLOWS_H

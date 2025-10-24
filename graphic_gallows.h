#ifndef GRAPHIC_GALLOWS_H
#define GRAPHIC_GALLOWS_H

#include "gallows.h"
#include "images.h"

class GraphicGallows : public Gallows
{
  public:
    GraphicGallows()
        : images_("../assets")
        , index_{0}
    {
    }

    void reset() override
    {
        index_ = 0;
    }

    std::size_t stage() const override
    {
        return index_;
    };

    std::size_t stages() const override
    {
        return images_.size();
    };

    void next() override
    {
        ++index_;
    };

    void draw() const override;

    void draw_state() const override
    {
        draw();
    }

  private:
    ImageLoader images_;
    std::size_t index_{0};
};

#endif // GRAPHIC_GALLOWS_H

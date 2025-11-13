#ifndef GALLOWS_H
#define GALLOWS_H

#include <cstddef>
#include <print>

class Gallows
{
  public:
    Gallows()
        : index_{0}
    {
    }
    virtual ~Gallows() = default;
    Gallows(const Gallows &other) = delete;
    Gallows(const Gallows &&other) = delete;

    virtual void reset()
    {
        index_ = 0;
    }

    virtual size_t stage() const
    {
        return index_;
    }

    virtual void next()
    {
        ++index_;
    }

    virtual size_t stages() const = 0;

    virtual void draw() const = 0;
    virtual void draw_state() const = 0;

  protected:
    size_t index_;
};

#endif // GALLOWS_H

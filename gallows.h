#ifndef GALLOWS_H
#define GALLOWS_H

#include <cstddef>

class Gallows
{
  public:
    Gallows() = default;
    virtual ~Gallows() = default;
    Gallows(const Gallows &other) = delete;

    virtual void reset() = 0;

    virtual size_t stage() const = 0;
    virtual size_t stages() const = 0;
    virtual void next() = 0;

    virtual void draw() const = 0;
    virtual void draw_state() const = 0;
};

#endif // GALLOWS_H

#ifndef GALLOWS_H
#define GALLOWS_H

#include <iostream>
#include <string>
#include <vector>

#include "ansi.h"

class Gallows
{
  public:
    Gallows() = default;
    virtual ~Gallows() = default;
    Gallows(const Gallows &other) = delete;

    virtual void reset() = 0;

    virtual std::size_t stage() const = 0;
    virtual std::size_t stages() const = 0;
    virtual void next() = 0;

    virtual void show() const = 0;
    virtual void draw_state() const = 0;
};

struct GallowsEntry
{
    unsigned int line;
    unsigned int column;
    std::string text;
};

class TextGallows : public Gallows
{
  public:
    TextGallows()
        : index_{0}
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
        return gallows_entries_.size();
    };

    void next() override
    {
        ++index_;
    };

    void show() const override;
    void draw_state() const override;

  private:
    static const std::vector<GallowsEntry> gallows_entries_;
    std::size_t index_{0};
};

#endif // GALLOWS_H

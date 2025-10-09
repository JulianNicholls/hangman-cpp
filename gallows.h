#ifndef GALLOWS_H
#define GALLOWS_H

#include <array>
#include <iostream>
#include <print>
#include <sstream>
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

class GallowsEntry
{
  public:
    GallowsEntry(unsigned int l, unsigned int c, std::string_view text)
        : line_(l)
        , column_(c)
        , text_(text)
    {
    }

    void show() const
    {
        std::istringstream lines{text_};
        unsigned int cur_line = line_;
        std::string str;

        while (std::getline(lines, str))
        {
            std::cout << ANSI::move_cursor(cur_line++, column_) << str;
        }
    }

  private:
    unsigned int line_;
    unsigned int column_;
    std::string text_;
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

    void show() const override
    {
        gallows_entries_[index_].show();
    }

    void draw_state() const override
    {
        for (size_t i = 0; i <= index_; ++i)
        {
            gallows_entries_[i].show();
        }
    }

  private:
    static const std::array<GallowsEntry, 11> gallows_entries_;
    std::size_t index_{0};
};

#endif // GALLOWS_H

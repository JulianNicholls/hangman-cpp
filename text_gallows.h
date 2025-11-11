#ifndef TEXT_GALLOWS_H
#define TEXT_GALLOWS_H

#include <array>
#include <print>
#include <sstream>
#include <string>

#include "ansi.h"
#include "gallows.h"

class TextGallowsEntry
{
  public:
    TextGallowsEntry(unsigned int l, unsigned int c, std::string_view text)
        : line_(l)
        , column_(c)
        , text_(text)
    {
    }

    void draw() const
    {
        std::istringstream lines{text_};
        unsigned int cur_line = line_;
        std::string str;

        while (std::getline(lines, str))
        {
            std::print("{}{}", ANSI::move_cursor(cur_line++, column_), str);
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

    std::size_t stages() const override
    {
        return gallows_entries_.size();
    };

    void draw() const override
    {
        gallows_entries_[index_].draw();
    }

    void draw_state() const override
    {
        for (size_t i = 0; i <= index_; ++i)
        {
            gallows_entries_[i].draw();
        }
    }

  private:
    static const std::array<TextGallowsEntry, 11> gallows_entries_;
    std::size_t index_{0};
};

#endif // TEXT_GALLOWS_H

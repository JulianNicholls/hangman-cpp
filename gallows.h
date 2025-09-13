#ifndef GALLOWS_H
#define GALLOWS_H

#include <format>
#include <string>
#include <vector>

#include "ansi.h"

namespace
{
const std::string land = "\n------------------------------------\n" + ANSI::reset;
const std::string top = " -----------------------\n";

const std::vector<std::string> old_gallows_text = {
    "\n\n\n\n\n\n" + land,
    "\n |\n |\n |\n |\n |\n" + land,
    top + " |\n |\n |\n |\n |\n" + land,
    top + " |/\n |\n |\n |\n |\n" + land,
    top + " |/     |\n |\n |\n |\n |\n" + land,
    top + " |/     |\n |      o\n |\n |\n |\n" + land,
    top + " |/     |\n |      o\n |      O\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |     /\n |\n" + land,
    top + " |/     |\n |      o\n |     /O\\\n |     / \\ \n |\n" + land};
}

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
};

struct TextGallows : public Gallows
{
  public:
    TextGallows()
        : index{0}
    {
    }

    void reset() override
    {
        index = 0;
    }

    std::size_t stage() const override
    {
        return index;
    };

    std::size_t stages() const override
    {
        return gallows_text.size();
    };

    void next() override
    {
        ++index;
    };

    std::string stage_text() const
    {
        return gallows_text[index];
    };

  private:
    static const std::vector<std::string> gallows_text;
    std::size_t index{0};
};

template <>
struct std::formatter<TextGallows>
{
    constexpr auto parse(std::format_parse_context &ctx)
    {
        return ctx.begin();
    }

    auto format(const TextGallows &g, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "{}", g.stage_text());
    }
};

#endif // GALLOWS_H

#ifndef GALLOWS_H
#define GALLOWS_H

#include <format>
#include <string>
#include <vector>

namespace
{
constexpr std::string reset = "\x1b[0m";
constexpr std::string dark_red = "\x1b[0;31m";
constexpr std::string light_red = "\x1b[31;1m";
constexpr std::string dark_green = "\x1b[0;32m";
constexpr std::string light_green = "\x1b[32;1m";
constexpr std::string brown = "\x1b[0;33m";
constexpr std::string yellow = "\x1b[33;1m";
constexpr std::string dark_blue = "\x1b[0;34m";
constexpr std::string light_blue = "\x1b[34;1m";
constexpr std::string dark_magenta = "\x1b[0;35m";
constexpr std::string light_magenta = "\x1b[35;1m";
constexpr std::string dark_cyan = "\x1b[0;36m";
constexpr std::string light_cyan = "\x1b[36;1m";
constexpr std::string grey = "\x1b[0;37m";
constexpr std::string white = "\x1b[37;1m";

const std::string land = "\n------------------------------------\n" + reset;
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

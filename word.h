#ifndef WORD_H
#define WORD_H

#include <format>
#include <ranges>
#include <vector>

namespace
{
std::string upper(std::string_view text)
{
    std::string output{};

    std::ranges::transform(text, std::back_inserter(output), toupper);

    return output;
}
}

struct Word
{
    Word(const std::string &text = "")
        : word(text)
    {
    }

    bool guess(char ltr);

    const std::string display() const
    {
        return upper(word);
    }

    bool in_word(char c) const
    {
        return word.find(c) != std::string::npos;
    }

    bool good(char c) const
    {
        return std::ranges::find(good_letters, c) != good_letters.end();
    }

    bool bad(char c) const
    {
        return std::ranges::find(bad_letters, c) != bad_letters.end();
    }

    bool guessed(char c) const
    {
        return good(c) || bad(c);
    }

    bool done() const
    {
        for (char ch : word)
        {
            if (!good(ch))
                return false;
        }

        return true;
    }

    std::string word;
    std::vector<char> good_letters;
    std::vector<char> bad_letters;
};

// Formatting the word gives it with dashes for unguessed letters and spaces between letters otherwise
template <>
struct std::formatter<Word>
{
    constexpr auto parse(std::format_parse_context &ctx)
    {
        return ctx.begin();
    }

    auto format(const Word &w, std::format_context &ctx) const
    {
        std::string out;

        for (auto c : w.word)
        {
            out += std::format("{} ", w.guessed(c) ? static_cast<char>(toupper(c)) : '_');
        }

        return std::format_to(ctx.out(), "{}", out);
    }
};

#endif // WORD_H

#include <format>
#include <vector>

struct Word
{
  public:
    Word(const std::string &text)
        : word(text)
    {
    }

    bool guess(char ltr);

    bool in_word(char c) const
    {
        return word.find(c) != std::string::npos;
    }

    bool guessed(char c) const
    {
        return std::ranges::find(guessed_letters, c) != guessed_letters.end();
    }

    std::string word;
    std::vector<char> guessed_letters;
};

template <>
struct std::formatter<Word>
{
    constexpr auto parse(std::format_parse_context &ctx)
    {
        return ctx.begin();
    }

    auto format(const Word &word, std::format_context &ctx) const
    {
        std::string out;

        for (auto c : word.word)
        {
            out += std::format("{} ", word.guessed(c) ? c : '_');
        }

        return std::format_to(ctx.out(), "{}", out);
    }
};

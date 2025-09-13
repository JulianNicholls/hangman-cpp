#ifndef WORDLIST_H
#define WORDLIST_H

#include <random>
#include <string>
#include <string_view>
#include <vector>

static std::mt19937 rng(std::random_device{}());

class Wordlist
{
  public:
    Wordlist(std::string_view filename);

    std::size_t size() const
    {
        return words_.size();
    }

    std::string random(std::string::size_type min_length = 1)
    {
        std::string word;

        do
        {
            word = words_[ud_(rng)];
        } while (word.size() < min_length);

        return word;
    }

  private:
    std::vector<std::string> words_;
    std::uniform_int_distribution<std::size_t> ud_;
};

#endif // WORDLIST_H

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

    std::string random()
    {
        return words_[ud_(rng)];
    }

  private:
    std::vector<std::string> words_;
    std::uniform_int_distribution<std::size_t> ud_;
};

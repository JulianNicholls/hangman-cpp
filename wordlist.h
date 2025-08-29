#include <string>
#include <string_view>
#include <vector>

class Wordlist
{
  public:
    Wordlist(std::string_view filename);
    std::size_t size() const
    {
        return words_.size();
    }

  private:
    std::vector<std::string> words_;
};

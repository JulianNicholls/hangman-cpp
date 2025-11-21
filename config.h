#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

class Config
{
  public:
    Config(const std::string &filename);

    const std::string &at(const std::string &key) const;
    // I now understand what is going on...
    // sum::at() is const, sum::[] is not.
    const std::string &operator[](const std::string &key) const;

  private:
    std::unordered_map<std::string, std::string> values_;
};

#endif // CONFIG_H

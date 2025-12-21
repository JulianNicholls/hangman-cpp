#include "config.h"

#include <fstream>
#include <print>
#include <ranges>

Config::Config(const std::string &filename)
{
    // std::println("Opening {}", filename);

    std::ifstream ifile(filename);
    std::string line;

    if (!ifile)
    {
        std::println("Could not open config file: {}", filename);
        return;
    }

    while (std::getline(ifile, line))
    {
        // There are at least two ways to do this...
        // This way with std::views::split, and using std::ranges::find_first_of and then using the delimiter offset

        // I still think it's perverse that std::views::split turns 'A1=B2' into [['A', '1'], ['B', '2']]
        // and not ["A1", "B2"] where [] denotes a range.

        auto parts = line | std::views::split('=');
        auto it = parts.begin();

        if (it != parts.end())
        {
            // std::string_view has a constructor that takes a range since C++23.
            std::string_view key(*it++);
            std::string_view value(*it);

            // std::println("  Config: Setting {} = {}", key, value);
            values_[std::string(key)] = value;
        }
    }
}

const std::string &Config::at(const std::string &key) const
{
    // std::println("retrieving {}: '{}'", key, values_[key]);

    return values_.at(key);
}

const std::string &Config::operator[](const std::string &key) const
{
    static std::string emptyStr = "";

    // std::println("retrieving {} via []: '{}'", key, values_[key]);

    try
    {
        return values_.at(key);
    }
    catch (std::out_of_range &e)
    {
        return emptyStr;
    }
}

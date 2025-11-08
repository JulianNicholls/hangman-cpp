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
        // There's at least two ways to do this...
        // This way with std::views::split and using std::ranges::find_first_of and then using the delimiter offset

        auto parts = line | std::views::split('=');
        auto it = parts.begin();

        if (it != parts.end())
        {
            std::string key((*it).begin(), (*it).end());
            ++it;
            std::string value((*it).begin(), (*it).end());

            std::println("  Config: Setting {} = {}", key, value);
            values_[key] = value;
        }
    }
}

const std::string &Config::at(const std::string &key)
{
    std::println("retrieving {}: '{}'", key, values_[key]);

    return values_[key];
}

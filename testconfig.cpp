#include <print>

#include "config.h"

int main()
{
    Config badcfg{"testconfig-not.cfg"};
    Config cfg{"testconfig.cfg"};

    auto istr = cfg.at("ivalue");
    auto bstr = cfg.at("bvalue");
    auto sstr = cfg.at("svalue");

    std::println("{}, {}, '{}'", istr, bstr, sstr);

    auto ibstr = cfg["ivalue"];
    auto bbstr = cfg["bvalue"];
    auto sbstr = cfg["svalue"];

    std::println("{}, {}, '{}'", ibstr, bbstr, sbstr);
}

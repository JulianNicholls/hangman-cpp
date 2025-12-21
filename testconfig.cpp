#include <print>

#include "config.h"

int main()
{
    Config badcfg{"testconfig-not.cfg"};
    Config cfg{"testconfig.cfg"};

    auto istr = cfg.at("ivalue");
    auto bstr = cfg.at("bvalue");
    auto sstr = cfg.at("svalue");
    auto mstr = ""; // cfg.at("mvalue"); // there isn't one, and it would throw

    std::println("{}, {}, '{}', '{}'", istr, bstr, sstr, mstr);

    auto ibstr = cfg["ivalue"];
    auto bbstr = cfg["bvalue"];
    auto sbstr = cfg["svalue"];
    auto mbstr = cfg["mvalue"]; // There isn't one, but it should be fine

    std::println("{}, {}, '{}', '{}'", ibstr, bbstr, sbstr, mstr);
}

#pragma once

#include <iostream>

#include "color.hpp"

namespace Color
{
    Rgb Rgb_from_hex(unsigned int const hex);
    unsigned int rgb_to_hex_int(Rgb const& color);
    Rgb Rgb_from_hex(std::string const& hex);
    std::string rgb_to_hex_string(Rgb const& color);
}
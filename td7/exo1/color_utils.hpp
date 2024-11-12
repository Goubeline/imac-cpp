#pragma once

#include <iostream>

#include "color.hpp"

namespace Color
{
    Rgb mix(Rgb const& color1, Rgb const& color2);
    float luminance(Rgb& color);
    Rgb invert(Rgb color);
    void grayscale(Rgb& color);
}
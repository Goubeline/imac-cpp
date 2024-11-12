#include <iostream>

#include "color.hpp"

namespace Color
{
    void Rgb::display()const
    {
        std::cout << "rgb(" << red << ", " << green << ", " << blue << ')';
    }
}
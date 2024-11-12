#include "color_utils.hpp"

namespace Color
{
    Rgb mix(Rgb const& color1, Rgb const& color2)
    {
        Rgb mean;
        mean.red = (color1.red + color2.red) / 2;
        mean.green = (color1.green + color2.green) / 2;
        mean.blue = (color1.blue + color2.blue) / 2;
        return mean;
    }

    float luminance(Rgb& color)
    {
        float red = color.red / 255.0;
        float green = color.green / 255.0;
        float blue = color.blue / 255.0;
        return  (0.2126 * red + 0.7152 * green + 0.0722 * blue); 
    }

    Rgb invert(Rgb color)
    {
        color.red = 255 - color.red;
        color.green = 255 - color.green;
        color.blue = 255 - color.blue;
        return color;
    }

    void grayscale(Rgb& color)
    {
        unsigned int lumi = 255 * luminance(color);
        color.red = lumi;
        color.blue = lumi;
        color.green = lumi;
    }
}
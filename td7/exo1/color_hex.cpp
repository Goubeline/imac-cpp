#include <iostream>
#include <sstream>

#include "color_hex.hpp"

namespace Color
{
    Rgb Rgb_from_hex(unsigned int const hex)
    {
        Rgb color;
        color.red = hex >> 16;
        color.green = (hex >> 8) & 0x0000ff;
        color.blue = hex & 0x0000ff;
        return color;
    }

    unsigned int rgb_to_hex_int(Rgb const& color)
    {
        return ((color.red << 16) + (color.green << 8) + color.blue);
    }

    Rgb Rgb_from_hex(std::string const& hex)
    {
        unsigned int num = std::stoi(hex, nullptr, 16);
        return Rgb_from_hex(num);
    }

    std::string rgb_to_hex_string(Rgb const& color)
    {
        unsigned int hex = rgb_to_hex_int(color);
        std::stringstream num;
        num << std::hex << hex;
        char hexa_tab[7];
        num.read(hexa_tab, 6);
        int zero = num.gcount();
        std::string hexa_str = hexa_tab;

        std::stringstream final;
        for (int i = 6; i > zero; i--)
        {
            final << '0';
        }
        
        final << hexa_str;
        return final.str();
    }
}
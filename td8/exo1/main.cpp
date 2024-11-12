#include <iostream>
#include <limits>

#include "color.hpp"
#include "color_hex.hpp"
#include "color_utils.hpp"

unsigned int get_hexa(std::string ieme_fois)
{
    std::string input;
    char hexa_table[6];
    char c;
    int number = 0;
    int pos;

    do
    {
        std::cout << "Entrez la " << ieme_fois << " couleur en hexadécimal: ";
        pos = 0;
        std::getline(std::cin, input);
        switch (input[0])
        {
        case '#':
            pos = 1;            
            break;
        case '0':
            if (input[1] == 'x')
            {
                pos = 2;
            }
            break;        
        default:
            break;
        }
        if (input.length() - pos != 6)
        {
            std::cin.clear();
            std::cout << "La couleur doit être composée de 6 chiffres/lettres." << std::endl;
            continue; 
        }
        
        for (size_t i = pos; i < input.length(); i++)
        {
            c = input[i];
            if (c >= '0' && c <= '9')
            {
                hexa_table[i - pos] = c - '0';
                number++;
                continue;
            }
            if (c >= 'a' && c <= 'f')
            {
                hexa_table[i - pos] = c - 'a' + 10;
                number++;
                continue;
            }
            if (c >= 'A' && c <= 'F')
            {
                hexa_table[i - pos] = c - 'A' + 10;
                number++;
                continue;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "La couleur en hexadécimal doit être composées de chiffres(0-9) et/ou lettres(a-f)." << std::endl;
            number = 0;
            break;
        }
    } while(number != 6);
   
    unsigned int hexa = hexa_table[0];
    for (int i = 1; i < 6; i++)
    {
        hexa = hexa << 4;
        hexa += hexa_table[i];
    }
    return hexa;
}

void print_rgb_hex(Color::Rgb const& color)
{
    color.display();
    std::cout<< " hex: " << Color::rgb_to_hex_string(color) << std::endl;
}

int main()
{

    unsigned int hex1 = get_hexa("première");
    unsigned int hex2 = get_hexa("deuxième");
    Color::Rgb c1 = Color::Rgb_from_hex(hex1);
    Color::Rgb c2 = Color::Rgb_from_hex(hex2);
    
    std::cout << "Couleur 1: ";
    print_rgb_hex(c1);
    
    std::cout << "Couleur 2: ";
    print_rgb_hex(c2);

    Color::Rgb cmean = Color::mix(c1, c2);
    std::cout << "Couleur mélangée: ";
    print_rgb_hex(cmean);

    std::cout << "Luminance: " << Color::luminance(cmean) << std::endl;

    Color::Rgb inverse = Color::invert(cmean);
    std::cout << "Couleur mélangée inversée: ";
    print_rgb_hex(inverse);

    Color::grayscale(cmean);
    std::cout << "Couleur mélangée en niveau de gris: ";
    print_rgb_hex(cmean);
}
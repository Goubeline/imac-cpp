#include <iostream>

int main()
{
    uint lettre;
    std::cout << "Entrez un nombre entre 1 et 26 : ";

    std::cin >> lettre;

    if (lettre - 1 > 25)
    {
        std::cout   << lettre << " n'est pas une lettre." << std::endl;
        return 1;
    }
    lettre += 64;
    std::cout   << "La lettre correspondante est : " << static_cast<char>(lettre) << std::endl;
    return 0;
}
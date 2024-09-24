#include <iostream>
#include <limits>

int main()
{
    unsigned int lettre;

    std::cout << "Entrez un nombre entre 1 et 26 : ";
    std::cin >> lettre;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur, veuillez entrez un nombre entier positif\n";
        std::cout << "Entrez un nombre entre 1 et 26 : ";
        std::cin >> lettre;
    }

    if (lettre - 1 > 25)
    {
        std::cout   << lettre << " n'est pas une lettre." << std::endl;
        return 1;
    }
    lettre += 64;
    std::cout   << "La lettre correspondante est : " << static_cast<char>(lettre) << std::endl;
    return 0;
}
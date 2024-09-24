#include <iostream>
#include <limits>

int main()
{
    unsigned int jours;

    std::cout << "Entrez un nombre de jours : ";
    std::cin >> jours;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur, veuillez entrez un nombre entier positif\n";
        std::cout << "Entrez un nombre de jours : ";
        std::cin >> jours;
    }

    std::cout   << jours << " jours correspondent à : "
                << jours / 36000 << " siecle " 
                << jours % 36000 / 360 << " annee " 
                << jours % 360 / 30 << " mois " 
                << jours % 30 / 7 << " semaine " 
                << jours % 7 << " jours" << std::endl;
    return 0;
}
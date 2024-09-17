#include <iostream>

int main()
{
    uint jours;
    std::cout << "Entrez un nombre de jours : ";

    std::cin >> jours;

    std::cout   << jours << " jours correspondent à : "
                << jours / 36000 << " siecle " 
                << jours % 36000 / 360 << " annee " 
                << jours % 36000 % 360 / 30 << " mois " 
                << jours % 36000 % 360 % 30 / 7 << " semaine " ;
    return 0;
}
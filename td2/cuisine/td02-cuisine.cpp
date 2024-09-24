#include <iostream>
#include <limits>

unsigned int wrong_type(std::string output)
{
    unsigned int x;
    std::cout << output;
    std::cin >> x;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur, veuillez entrez un nombre entier positif\n";
        std::cout << output;
        std::cin >> x;
    }
    
    return x;
}
int main()
{
    unsigned int pomme_de_terre = wrong_type("Nombre de sac de patates à acheter : ");
    unsigned int carotte = wrong_type("Nombre de carottes à acheter : ");
    unsigned int salade = wrong_type("Nombre de salades à acheter : ");

    float cout = pomme_de_terre * 3 + salade * 1.2 + carotte * 0.375;
    std::cout   << "Le prix total de la commande est de " << cout << " €"<< std::endl;
    return 0;
}

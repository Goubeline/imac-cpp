#include <iostream>

int main()
{
    uint pomme_de_terre;
    uint carotte;
    uint salade;
    std::cout << "Entrez le nombre de sacs de pommes de terre : ";
    std::cin >> pomme_de_terre;
    std::cout << "Entrez le nombre de carottes : ";
    std::cin >> carotte;
    std::cout << "Entrez le nombre de salades : ";
    std::cin >> salade;

    float cout = pomme_de_terre * 3 + salade * 1.2 + carotte * 0.375;
    std::cout   << "La lettre correspondante est : " << cout << std::endl;
    return 0;
}
#include <iostream>

int main()
{
    int sum = 0;
    int val = 0;
    float iter = -1;
    do
    {
        iter++;
        sum += val;
        std::cout << "Entrez un nombre entier à ajouter : ";
        std::cin >> val;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "La valeur demandée doit être un nombre entier\n";
            std::cin.clear();
            std::cin.ignore();
            val = 0;
            iter--;
        }
    } while (val >= 0);

    iter = {(iter == 0) ? 0 : sum/iter};
    std::cout << "La somme des nombres positif donnés est : " << sum << std::endl 
            << "Leur moyenne est : " << iter << std::endl;
}
#include <iostream>
#include <limits>

int wrong_type()
{
    int x;

    do
    {
        std::cout << "Saisir un entier : ";
        std::cin >> x;
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre\n";
    } while(true);
    
    return x;
}

int main()
{
    int integer = wrong_type();
    
    std::string texte {(integer < 0) ? " est négatif" : " est positif"};
    std::cout << integer << texte << std::endl;

    return 0;
}
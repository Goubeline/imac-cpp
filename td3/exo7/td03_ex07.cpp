#include <iostream>
#include <limits>

int main()
{
    int syracuse;
    do
    {
        std::cout << "Saisir un nombre pour commncer la série de Syracuse : ";
        std::cin >> syracuse;
        if (!std::cin.fail() && std::cin.peek() == '\n' && (syracuse > 0))
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier positif " << std::endl;
    } while(true);

    std::cout << syracuse;
    while (syracuse != 1)
    {
        syracuse = (syracuse % 2 == 0) ? syracuse /2 : syracuse * 3 + 1;
        std::cout << ", " << syracuse;
    }
    
    return 0;    
}
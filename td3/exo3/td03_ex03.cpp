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
        std::cout << "La valeur entrée doit être un nombre entier\n";
    } while(true);
    
    return x;
}

int main()
{
    int integer = wrong_type();
    std::cout << integer << 
       ((integer % 2 == 0) ? " est un nombre pair" : " est un nombre impair") << std::endl;
    while (integer > 1)
    {
        integer -= 2;
        std::cout << integer << '\n';
    }

    return 0;
}
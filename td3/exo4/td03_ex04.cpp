#include <iostream>
#include <limits>

unsigned int wrong_type()
{
    int x;

    do
    {
        std::cout << "Saisir l'age: ";
        std::cin >> x;
        if (x < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Il nous faut un nombre positif\n";
            continue;
        }
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
    int age = wrong_type();
    std::cout << ((age > 17) ? " Tu es majeur(e)" : "Tu es mineur(e)") << std::endl;

    return 0;
}
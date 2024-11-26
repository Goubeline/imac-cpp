#include <iostream>
#include <limits>

void print_int(int *number)
{
    std::cout << "Le nombre donne: " << *number << std::endl;
}

int main()
{
    int* number = {new int};
    do
    {
        std::cout << "Saisir un nombre entier: ";
        std::cin >> *number;

        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier" << std::endl;
    } while(true);
    print_int(number);
    std::cout << "Et son adresse memoire: " << number << std::endl; 

    delete(number);
    return 1;
}
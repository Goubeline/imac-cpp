#include <iostream>
#include <limits>

int sum(int const& sum1, int const& sum2)
{
    return sum1 + sum2;
}

int main()
{
    int a; 
    int b;
    do
    {
        std::cout << "Saisir le premier nombre à sommer : ";
        std::cin >> a;

        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier" << std::endl;
    } while(true);
     do
    {
        std::cout << "Saisir le deuxième nombre à sommer : ";
        std::cin >> b;

        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier" << std::endl;
    } while(true);   

    const int& ref_a = a;
    const int& ref_b = b;
    
    std::cout << "La somme de " << a << " et " << b << " est " << sum(ref_a, ref_b) <<std::endl;
    return 0;
}

#include <iostream>
#include <limits>

size_t factorielle(size_t const& facto)
{
    if (facto <= 1)
    {
        return 1;
    }
    return facto * factorielle(facto - 1);
}

int main()
{
    int a; 
    do
    {
        std::cout << "Saisir le nombre à factorielliser : ";
        std::cin >> a;

        if (!std::cin.fail() && std::cin.peek() == '\n' && a >= 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier positif" << std::endl;
    } while(true);


    const size_t& ref_a = a;
    
    std::cout <<a << "! = " << factorielle(ref_a) <<std::endl;
    return 0;
}
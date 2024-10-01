#include <array>
#include <iostream>
#include <limits>

int main()
{
    size_t number_;

    do
    {
        std::cout << "Saisir un nombre supérieur à 1 000 000: ";
        std::cin >> number_;

        if (!std::cin.fail() && std::cin.peek() == '\n' && number_ > 1000000)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier supérieur à 1 000 000" << std::endl;
    } while(true);
    
    std::array<size_t, 10> digit {};
    size_t number = number_;

    while (number != 0)
    {
        digit[number % 10] += 1;
        number /= 10;
    }
    
    size_t pos = 0;
    for (size_t i = 1; i < digit.size(); i++)
    {
        if (digit[i] > digit[pos])
        {
            pos = i;
        }
    }
    std::cout << "Le chiffre le plus présent dans " << number_ << " est " << pos <<std::endl;
    return 0;
}

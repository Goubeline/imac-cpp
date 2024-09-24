#include <iostream>
#include <limits>

float wrong_type()
{
    float x;
    std::cout << "Entrez un nombre à sommer : ";
    std::cin >> x;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur, veuillez entrez un nombre à sommer : ";
        std::cin >> x;
    }
    
    return x;
}

int main()
{
    float x = wrong_type();
    float y = wrong_type();
    float z = wrong_type();

    float sum = x + y + z;
    float aver = sum / 3;

    std::cout << "somme + moyenne : " << sum + aver << std::endl;
    return 0;
}
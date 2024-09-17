#include <iostream>

int main()
{
    int eleven = 11;
    std::cout << eleven << std::endl;

    // on obtient 5 parce que eleven est un entier
    std::cout << eleven / 2 << std::endl;

    std::cout << static_cast<float>(eleven) / 2.0 << std::endl;
    return 0;
}
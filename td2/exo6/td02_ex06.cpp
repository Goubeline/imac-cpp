#include <iostream>

int main()
{
    float const pi {3.141592};
    float a {pi*3}; // je veux le résultat de pi (environ 3.141592) fois 3
    int b {8};

    a += 20;  // je veux ajouter le nombre 20 à la valeur de b

    b = b * 15; // je veux modifier la valeur de b en la multipliant par 15

    std::cout << "a: " << a << std::endl;

    std::cout << "b: " << b << std::endl;

    return 0;
}
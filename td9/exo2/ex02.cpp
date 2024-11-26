#include <iostream>
#include <limits>
#include <vector>
#include <random>

std::vector<int> table_generator()
{
    srand(time(0));
    std::vector<int> vec;
    for (int i = 0; i < 100; i++)
    {
        vec.push_back(rand() % 100);
    }
    return vec;
}

int* superior_90(std::vector<int>& table)
{
    int* sup = nullptr;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i] > 90)
        {
            sup = &table[i];
            break;
        }
    }

    return sup;
}

size_t sum_noptr(int* num, int size)
{
    size_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(num + i);
    }
    return sum;
}

int* sum(std::vector<int> const& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return new int {sum};
}

int main()
{
    std::vector<int> vec = table_generator();

    std::cout << "vecteur: " << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << std::endl;

    int* sup90 = superior_90(vec);
    if (sup90 == nullptr)
    {
        std::cout << "Il n'y a pas de valeur superieur a 90." << std::endl;
    }
    else
    {
        std::cout << "La premiere valeur superieur a 90 est: " << *sup90 << "." << std::endl;
    }
    std::cout << "La somme des valeurs du vecteur est: " << sum_noptr(&vec[0], 100) << '.' << std::endl;
    int *somme = sum(vec);
    std::cout << "Le pointeur de la somme des valeurs du vecteur contient: " << *somme << '.' << std::endl;
    delete(somme);
    return 1;
}
#include <iostream>
#include <limits>
#include <random>

float* table_generator()
{
    srand(time(0));
    // attention ici les valeurs ne sont pas initialisées
    float* array_ptr {new float[100]};
    for (size_t i = 0; i < 100; i++)
    {
        array_ptr[i] = (static_cast<float>(rand()) / RAND_MAX) * 100;
    }
    return array_ptr;
}

float* max(float* &table, int size)
{
    float* sup = &table[0];
    for (int i = 1; i < size; i++)
    {
        if (table[i] > *sup)
        {
            sup = &table[i];
        }
    }
    return sup;
}

float* thresholdFilter(float const* const array, size_t const size, float const threshold, size_t& new_size)
{
    float* vec = new float[100];
    new_size = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > threshold)
        {
            vec[new_size] = array[i];
            new_size++;
        }
    }
    return vec;
}

int main()
{
    
    float* vec = table_generator();

    std::cout << "vecteur: " << vec[0];
    for (int i = 1; i < 100; i++)
    {
        std::cout << ", " << vec[i];
    }
    std::cout << std::endl;

    std::cout << "Le maximum est: " << *max(vec, 100) << "." << std::endl;

    size_t new_size;
    float* somme = thresholdFilter(vec, 100, 90, new_size);
    std::cout << "Les valeurs supérieurs à 90 sont: " << std::endl;

    if (new_size > 0)
    {
        std::cout << somme[0];
    }
    
    for (int i = 0; i < new_size; i++)
    {
        std::cout << ", " << somme[i];
    }
    delete[] somme;
    delete[] vec;
    return 1;}
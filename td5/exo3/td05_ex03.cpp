#include <iostream>
#include <limits>
#include <vector>

void fibo(int n, std::vector<size_t>& fibo_table)
{
    if (n <= 2)
    {
        return;
    }
    fibo_table.push_back(fibo_table[fibo_table.size() - 1] + fibo_table[fibo_table.size() - 2]);
    return fibo(n - 1, fibo_table);
}

int main()
{
    int a; 
    do
    {
        std::cout << "Saisir le nombre à d'éléments de la suite de Fibonacci : ";
        std::cin >> a;

        if (!std::cin.fail() && std::cin.peek() == '\n' && a > 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il nous faut un nombre entier positif" << std::endl;
    } while(true);

    std::vector<size_t> fibo_table = {0, 1};
    fibo(a,fibo_table);
    std::cout << "Les " << a << " premiers nombres de la suite de Fibonacci en récursif :" <<std::endl << fibo_table[0];
    for (size_t i = 1; i < a; i++)
    {
        std::cout << ", " << fibo_table[i];
    }
    std::cout << std::endl;

    std::cout << "Les " << a << " premiers nombres de la suite de Fibonacci en itératif :" <<std::endl << '0';
    size_t low = 0;
    size_t high = 1;
    size_t buf;
    for (int i = 1; i < a; i++)
    {
        std::cout << ", " << high;
        buf = high;
        high = low + high;
        low = buf;
    }
    std::cout << std::endl;
    return 0;
}
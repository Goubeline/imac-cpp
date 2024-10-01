#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

int main()
{
    size_t dwarf_count;
    
    do
    {
        std::cout << "Saisir le nombre de nain que vous voulez : ";
        std::cin >> dwarf_count;
        if (!std::cin.fail() && std::cin.peek() == '\n' && dwarf_count > 2)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier supérieur à 2\n";
    } while(true);
    std::vector<int> calories {};

    // std::srand permet de fixer la "seed" du générateur aléatoire (pour avoir des résultats reproductibles)
    std::srand(42);
    
    for (int i = 0; i < dwarf_count; ++i)
    {
      calories.push_back(rand() % 24000 + 100);
    }

    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int min = calories[0];
    // affichage optionnel des calories transportées par chaque nain
    for (int const c : calories)
    {
        if (c < min)
        {
            min = c;
            continue;
        }
        if (c > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = c;
            continue;
        }
        if (c > max2)
        {
            max3 = max2;
            max2 = c;
            continue;
        }
        if (c > max3)
        {
            max3 = c;
        }    
    }
    std::cout << "La quantité de provision la plus grande transportée par un nain est " << max1 << std::endl;
    std::cout << "La quantité de provision la plus petite transportée par un nain est " << min << std::endl;
    std::cout << "La somme des 3 quantités de provision les plus grandes transportées par un nain est " << max1 + max2 + max3 << std::endl;
    return 0;
}
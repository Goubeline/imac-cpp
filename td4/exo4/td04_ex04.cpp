#include <iostream>
#include <vector>
#include <limits>

void binary_search(std::vector<size_t> *table, size_t up_bound, size_t low_bound, size_t elem)
{
    if (up_bound == low_bound)
    {
        if (elem == table[0][up_bound])
        {
            return;
        }
        if (elem < table[0][up_bound])
        {
            table[0].insert(table[0].begin() + up_bound, elem);
           
        }
        else
        {
            table[0].insert(table[0].begin() + up_bound + 1, elem);
        }
        return;
    }
    size_t mid = (up_bound + low_bound) / 2;
    if (elem <= table[0][mid])
    {
        return binary_search(table, mid, low_bound, elem);
    }
    return binary_search(table, up_bound, mid + 1, elem);
    
}

size_t input(std::string texte)
{
    size_t elem;
    
    do
    {
        std::cout << texte;
        std::cin >> elem;
        if (!std::cin.fail() && std::cin.peek() == '\n' && elem > 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier supérieur à 0" << std::endl;
    } while(true);

    return elem;
}

int main()
{
    size_t level = input("Saisir le niveau terminé : ");
    size_t nb_foes {input("Saisir le nombre d'ennemis tués : ")};
    std::vector<size_t> ennemies {};
    for (size_t i = 0; i < nb_foes; i++)
    {
        std::cout << "Ennemi numéro" << i + 1 << std::endl;
        ennemies.push_back(input("Niveau de l'ennemi : "));
    }
    
    std::vector<size_t> energy_points = {0};
    size_t mult;
    for (size_t ennemy : ennemies)
    {
        mult = ennemy;
        while (mult < level)
        {
            binary_search(&energy_points, energy_points.size() - 1, 0, mult);
            mult += ennemy;
        }
    }

    size_t points = 0;
    for (size_t energy : energy_points)
    {
        points += energy;
    }
    std::cout << "Vous avez gagné " << points << " points d'énergie" << std::endl;
    return 0;
}
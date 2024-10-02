#include <iostream>
#include <vector>
#include <limits>


void table_writer(std::vector<char> table)
{
    std::cout << '[';
    for (size_t i = 0; i < table.size() - 1; i++)
    {
        std::cout << table[i] << ", ";
    }
    std::cout << table[table.size() - 1] << ']' << std::endl;
}

int main()
{
    std::vector<char> entiers {};
    char c;
    do
    {
        std::cout << "Saisir 10 chiffres entre 0 et 5 : ";
        while (std::cin.get(c))
        {
            if (c == 10)
            {
                if (entiers.size() != 10)
                {
                    std::cin.clear();
                    std::cout << "Il faut 10 chiffres entre 0 et 5" << std::endl;
                    c = 0;
                }                
                break;
            }
            if (!(c >= '0' && c<= '5'))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Il ne faut que des chiffres entre 0 et 5" << std::endl;
                entiers.clear();
                break;
            }
            entiers.push_back(c);
        }

    } while(c != 10);

    std::cout << "Votre liste avant modification" << std::endl;
    table_writer(entiers);

    int nb3 = 0;
    for (size_t i = 0; i < entiers.size() - nb3; i++)
    {
        if (entiers[i] == '3')
        {
            entiers.erase(entiers.begin() + i);
            entiers.push_back('0');
            nb3++;
        }
    }

    std::cout << "Votre liste après modification" << std::endl;
    table_writer(entiers);
    return 0;
}
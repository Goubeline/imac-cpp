#include <iostream>
#include <limits>
#include <vector>

void table_writer(std::vector<int> table)
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
    std::vector<int> entiers {};
    char c;
    do
    {
        std::cout << "Saisir votre numéro de carte bancaire (vous pouvez mettre des esapces) : ";
        while (std::cin.get(c))
        {
            if (c == 10)
            {
                if (entiers.size() != 16)
                {
                    std::cin.clear();
                    std::cout << "Il faut 16 chiffres entre 0 et 9" << std::endl;
                    c = 0;
                }                
                break;
            }
            if (c == ' ')
            {
                continue;
            }
            
            if (!(c >= '0' && c<= '9'))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Il ne faut que des chiffres entre 0 et 9" << std::endl;
                entiers.clear();
                break;
            }
            entiers.push_back(c - 48);
        }

    } while(c != 10);

    table_writer(entiers);
    int buf;
    int sum = 0;
    for (size_t i = 1; i < 16; i += 2)
    {
        buf = entiers[i] * 2;
        if (buf > 9)
        {
            buf -= 9;
        }
        entiers[i] = buf;

        sum = sum + buf + entiers[i - 1];
    }
    
    table_writer(entiers);

    if (sum % 10 == 0)
    {
        std::cout << "Votre numéro de carte est valide" << std::endl;
    }
    else
    {
        std::cout << "Votre numéro de carte est invalide" << std::endl;
    }
    return 0;    
}
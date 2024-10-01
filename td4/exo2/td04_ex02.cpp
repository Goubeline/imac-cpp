#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::vector<char> palin;
    char c = 0;
    size_t lettres = 0;

    do
    {
        std::cout << "Saisir un mot : ";
        while (std::cin.get(c))
        {
            if (c == 10)
            {
                if (palin.size() == 0)
                {
                    std::cin.clear();
                    std::cout << "Le mot doit contenir des lettres" << std::endl;
                    c = 0;
                }                
                break;
            }
            if (!((c >= 65 && c<=90) || (c >= 97 && c<=122)))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Le mot ne doit contenir que des lettres" << std::endl;
                lettres = 0;
                palin.clear();
                break;
            }
            palin.push_back(c);
            lettres++;   
        }

    } while(c != 10);

    for (size_t i = 0; i < lettres/2; i++)
    {
        if (palin[i] != palin[palin.size() - i - 1])
        {
            std::cout << "Ce n'est pas un palindrome" << std::endl;
            return 0;
        }
        
    }
    
    std::cout << "C'est un palindrome" << std::endl;
    return 0;
}
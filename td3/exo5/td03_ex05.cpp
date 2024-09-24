#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

int wrong_type()
{
    int x;

    do
    {
        std::cout << "Saisir un nombre de tentatives : ";
        std::cin >> x;
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier\n";
    } while(true);
    
    return x;
}

int main()
{
  // Initialisation du générateur de nombres aléatoires avec la fonction time()
    std::srand(std::time(nullptr));
    int alea = std::rand() % 100 + 1;
    int max = wrong_type();
    bool trouve = false;
    int essai;

    for (int tentative = 0; tentative < max; tentative++)
    {
        std::cout << "Entrez un nombre entre 1 et 100: ";
        std::cin >> essai;
        if (essai < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Il nous faut un nombre positif\n";
            continue;
        }
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            if (essai > alea)
            {
                std::cout << essai << " est plus grand que le nombre aléatoire\n";
            
            }
            else if (essai < alea)
            {
                std::cout << essai << " est plus petit que le nombre aléatoire\n";
            }
            else
            {
                trouve = true;
                break;
            }
            continue;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier\n";
    }
    
    std::cout << ((trouve) ? "Bravo, le nombre aléatoire était bien : " : "Dommage, tu as utilisé toutes tes tentatives, le nombre à trouver était : ") << alea << std::endl;
    return 0;
}
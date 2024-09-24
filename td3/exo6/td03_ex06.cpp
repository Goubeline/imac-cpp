#include <iostream>
#include <limits>

int main()
{
    int forme;
    do
    {
        std::cout << "0 pour triangle rectangle | 1 pour sapin de noël | 2 pour carré : ";
        std::cin >> forme;
        if (!std::cin.fail() && std::cin.peek() == '\n' && (forme >= 0 && forme < 3))
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être 0, 1 ou 2 \n";
    } while(true);

    int x;
    do
    {
        std::cout << "Saisir la hauteur du ";
        switch (forme)
        {
        case 0:
            std::cout << "triangle : ";
            break;
        case 1:
            std::cout << "sapin : ";
            break;
        default:
            std::cout << "carré : ";
            break;
        }

        std::cin >> x;
        if (!std::cin.fail() && std::cin.peek() == '\n' && x >= 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "La valeur entrée doit être un nombre entier positif \n";
    } while(true);
    
    if (!forme)
    {
        for (int i = 1; i <= x; i++)
        {
            for (int j = 0; j < i; j++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
    else if (forme == 2)
    {
        for (int i = 0; i < x; i++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;

        for (int i = 2; i < x; i++)
        {
            std::cout << '*';
            for (int j = 0; j < x - 2; j++)
            {
                std::cout << ' ';
            }
            std::cout << '*' << std::endl;
        }
        if (x != 1)
        {
            for (int i = 0; i < x; i++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int i = 1; i <= x; i++)
        {
            for (int j = i; j < x; j++)
            {
                std::cout << ' ';
            }
            for (int j = 0; j < (2*i - 1); j++)
            {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
    return 0;    
}
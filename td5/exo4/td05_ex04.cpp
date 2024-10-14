#include <iostream>
#include <vector>
#include <limits>

//fonctions demandées
float average(const std::vector<int>& table)
{
    float sum = 0;
    for (int i : table)
    {
        sum += static_cast<float> (i) / static_cast<float> (table.size());
    }
    return sum;
}
float average(const std::vector<float>& table)
{
    float sum = 0;
    for (float i : table)
    {
        sum += i / static_cast<float> (table.size());
    }
    return sum;
}

//imprime un vecteur d'int ou de float
void table_writer(std::vector<float> table)
{
    std::cout << '[';
    for (size_t i = 0; i < table.size() - 1; i++)
    {
        std::cout << table[i] << ", ";
    }
    std::cout << table[table.size() - 1] << ']' << std::endl;
}
void table_writer(std::vector<int> table)
{
    std::cout << '[';
    for (size_t i = 0; i < table.size() - 1; i++)
    {
        std::cout << table[i] << ", ";
    }
    std::cout << table[table.size() - 1] << ']' << std::endl;
}

//ascii to float
float atof(std::string num, int& len)
{
    float n = 0;
    bool negatif = false;
    bool virgule = false;
    if (num[0] == '-')
    {
        if (len == 1)
        {
            len = -1;
            return -1;
        }
        negatif = true;
    }
    int i = negatif;
    while(i < len)
    {
        if (num[i] == '.' || num[i] == ',')
        {
            virgule = true;
            i++;
            break;
        }
        
        n *= 10;
        n += num[i] - 48;
        i++;
    }

    if (virgule)
    {
        float decimal = 0.1;
        while (i < len)
        {
            n += (num[i] - 48) * decimal;
            decimal /= 10;
            i++;
        }
    }
    
    if (negatif)
    {
        n *= -1;
    }
    
    return n;
}

//ascii to int
int atoi(std::string num, int& len)
{
    int n = 0;
    bool negatif = false;
    if (num[0] == '-')
    {
        if (len == 1)
        {
            len = -1;
            return -1;
        }
        negatif = true;
    }
    
    for (int i = negatif; i < len; i++)
    {
        n *= 10;
        n += num[i] - 48;
    }

    if (negatif)
    {
        n *= -1;
    }
    
    return n;
}

//récupérer les données utilisateur int
void want_integer(std::vector<int>& entiers)
{
    char c = 0;
    std::string num;
    int n = 0;
    int buf;
    do
    {
        std::cout << "Saisir les nombres dont on veut la moyenne (séparer par des espaces) : ";
        while (std::cin.get(c))
        {
            if (c == 10)
            {
                if (n != 0)
                {
                    buf = atoi(num, n);
                    if (n == -1)
                    {
                        std::cin.clear();
                        std::cout << "Il ne faut que des nombres" << std::endl;
                        entiers.clear();
                        num.clear();
                        n = 0;
                        c = 0;
                        break;
                    }
                    entiers.push_back(buf);
                    num.clear();
                    n = 0;
                    break;
                }
                if (entiers.size() == 0)
                {
                    std::cin.clear();
                    std::cout << "Il faut au moins un nombre" << std::endl;
                    c = 0;
                }                
                break;
            }

            if (c == ' ')
            {
                if (n != 0)
                {
                    buf = atoi(num, n);
                    if (n == -1)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Il ne faut que des nombres" << std::endl;
                        entiers.clear();
                        num.clear();
                        n = 0;
                        break;
                    }
                    entiers.push_back(buf);
                    num.clear();
                    n = 0;
                    continue;
                }
                continue;
            }

            if (!((c >= '0' && c<= '9') || (n == 0 && c == '-')))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Il ne faut que des nombres" << std::endl;
                entiers.clear();
                num.clear();
                n = 0;
                break;
            }
            num.push_back(c);
            n++;
        }
    } while(c != 10);
    return;
}

//récupérer les données utilisateur float
void want_float(std::vector<float>& flottant)
{
    char c = 0;
    std::string num;
    int n = 0;
    float buf;
    bool virgule = false;
    do
    {
        std::cout << "Saisir les nombres dont on veut la moyenne (séparer par des espaces) : ";
        while (std::cin.get(c))
        {
            if (c == 10)
            {
                if (n != 0)
                {
                    buf = atof(num, n);
                    if (n == -1)
                    {
                        std::cin.clear();
                        std::cout << "Il ne faut que des nombres" << std::endl;
                        flottant.clear();
                        num.clear();
                        n = 0;
                        c = 0;
                        break;
                    }
                    flottant.push_back(buf);
                    num.clear();
                    virgule = false;
                    n = 0;
                    break;
                }
                if (flottant.size() == 0)
                {
                    std::cin.clear();
                    std::cout << "Il faut au moins un nombre" << std::endl;
                    c = 0;
                }                
                break;
            }

            if (c == ' ')
            {
                if (n != 0)
                {
                    buf = atof(num, n);
                    if (n == -1)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Il ne faut que des nombres" << std::endl;
                        flottant.clear();
                        num.clear();
                        n = 0;
                        break;
                    }
                    flottant.push_back(buf);
                    num.clear();
                    virgule = false;
                    n = 0;
                }
                continue;
            }

            if (!((c >= '0' && c<= '9') || (n == 0 && c == '-')))
            {
                if ((c == '.' || c == ',') && !virgule)
                {
                    virgule = true;
                    num.push_back(c);
                    n++;
                    continue;
                }
                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Il ne faut que des nombres" << std::endl;
                flottant.clear();
                num.clear();
                n = 0;
                break;
            }
            num.push_back(c);
            n++;
        }
    } while(c != 10);
    return;
}

int main()
{
    std::vector<int> entiers = {};
    std::vector<float> flottants {};
    int a;
    do
    {
        std::cout << "Voulez vous une moyenne d'entiers (0) ou de flottants(1) : ";
        std::cin >> a;

        if (!std::cin.fail() && std::cin.peek() == '\n' && (a == 0 || a == 1))
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Répondez 0 ou 1" << std::endl;
    } while(true);


    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
    switch (a)
    {
    case 0:
        want_integer(entiers);
        std::cout << "Votre liste :" << std::endl;
        table_writer(entiers);
        std::cout << "Sa moyenne : " << average(entiers) << std::endl;
        break;
        
    default:
        want_float(flottants);
        std::cout << "Votre liste :" << std::endl;
        table_writer(flottants);
        std::cout << "Sa moyenne : " << average(flottants) << std::endl;
        break;
    }
    return 0;
}
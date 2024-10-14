#include <iostream>
#include <vector>
#include <limits>


void MintoMaj(std::string& phrase)
{
    for(char& c : phrase)
    {
        if (c <= 'z' && c >= 'a')
        {
            c = c + 'A' - 'a';
            continue;
        }

        if (c <= 'Z' && c >= 'A')
        {
            c = c + 'a' - 'A';
            continue;
        }       
    }
    return;
}

int nbwords(std::string& phrase)
{
    int words = 0;
    size_t i = 0;
    while (i < phrase.size() && phrase[i] == ' ')
    {
        i++;
    }
    
    while (i < phrase.size())
    {
        if (phrase[i] == ' ')
        {
            words++;
            while (phrase[i] == ' ')
            {
                i++;
            }
        }
        i++;
    }
    if (phrase[phrase.size() - 1] != ' ')
    {
        words++;
    }
    
    return words;
}

int nbvowels(std::string& phrase)
{
    int vow = 0;
    for (char c : phrase)
    {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
            || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'y' || c == 'Y')
        {
            vow++;
        }
    }
    return vow;
}

void verlan(std::string& phrase)
{
    char buf;
    for (size_t i = 0; i < phrase.size() / 2; i++)
    {
        buf = phrase[i];
        phrase[i] = phrase[phrase.size() - i - 1];
        phrase[phrase.size() - i - 1] = buf;
    }
    return;
}

bool isnumber(std::string& phrase)
{
    if (phrase.size() == 0)
    {
        return false;
    }
    
    size_t pos = 0;
    if (phrase.size() > 1 && phrase[0] == '-')
    {
        pos++;
    }
    while (pos < phrase.size())
    {
        if (!std::isdigit(phrase[pos]))
        {
            return false;
        }
        pos++;
    }
    return true;    
}

int main()
{
    std::string phrase;
    std::cout << "Saisir une phrase : ";
    std::getline(std::cin, phrase);
    std::string copie = phrase;

    std::cout << "Phrase originale :" << std::endl << phrase << std::endl;
    MintoMaj(copie);
    std::cout << "Majuscules et minuscules inversées :" << std::endl << copie << std::endl;
    std::cout << "Elle contient " << nbvowels(phrase) << " voyelles." << std::endl;
    std::cout << "Elle contient " << nbwords(phrase) << " mots." << std::endl;
    copie = phrase;
    verlan(copie);
    std::cout << "Phrase à l'envers :" << std::endl << copie <<  std::endl;
    std::cout << (isnumber(phrase) ? "C'est un nombre entier." : "Ce n'est pas un nombre entier.") << std::endl;
    return 0;
}
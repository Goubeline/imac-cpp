#include <iostream>
#include <vector>
#include <limits>

bool pangame(std::string phrase)
{
    std::vector<bool> alphabet(26, false);
    for (char i : phrase)
    {
        if ('a' <= i && i <= 'z')
        {
            alphabet[i - 'a'] = true;
            continue;
        }

        if ('A' <= i && i <= 'Z')
        {
            alphabet[i - 'A'] = true;
            continue;
        }        
    }
    for(bool lettre : alphabet)
    {
        if (!lettre)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string phrase;
    std::cout << "Saisir une phrase : ";
    std::getline(std::cin, phrase);

    std::cout << phrase << std::endl
        << (pangame(phrase) ? "Est un pangame." : "N'est pas un pangame.") << std::endl;
    return 0;
}
#include <istream>
#include <iostream>
#include <limits>

enum class Article { Alimentation, Vetements, Chaussures, Autre };

// C'est un mécanisme avancé, vous n'avez pas besoin de comprendre comment ça marche.
// On en reparlera au second semestre.
// retenez juste que ça permet de convertir une entrée de l'utilisateur en Article.
std::istream& operator>>(std::istream& is, Article& article)
{
    std::string articleAsString;
    is >> articleAsString;

    if (articleAsString == "Alimentation") {
        article = Article::Alimentation;
    } else if (articleAsString == "Vetements") {
        article = Article::Vetements;
    } else if (articleAsString == "Chaussures") {
        article = Article::Chaussures;
    } else if (articleAsString == "Autre") {
        article = Article::Autre;
    } else {
        is.setstate(std::ios::failbit);
    }

    return is;
}

int main ()
{
    Article article;
    float prix;
    bool has_card;
    int age;
    do
    {
        std::cout << "Veuillez donner le type de l'article que vous souhaiter acheter : ";
        std::cin >> article;
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ce type d'article nous est inconnu" << std::endl;
    } while(true);

    do
    {
        std::cout << "Veuillez donner le prix de l'article : ";
        std::cin >> prix;
        if (!std::cin.fail() && std::cin.peek() == '\n' && prix > 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Le prix doit être un nombre positif" << std::endl;
    } while(true);

    do
    {
        std::cout << "Possédez vous la carte du magasin (0 = non, 1 = oui)?";
        std::cin >> has_card;
        if (!std::cin.fail() && std::cin.peek() == '\n')
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Veuillez répondre 1 ou 0" << std::endl;
    } while(true);

    do
    {
        std::cout << "Veuillez donner votre age : ";
        std::cin >> age;
        if (!std::cin.fail() && std::cin.peek() == '\n'  && age >= 0)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Il doit s'agir d'un nombre entier" << std::endl;
    } while(true);

    float reduc; 
    switch (article)
    {
    case Article::Autre:
        reduc = 0;
        break;
    case Article::Vetements:
        reduc = (has_card) ? 0.15 : 0.10;
        break;
    case Article::Alimentation:
        reduc = (has_card) ? 0.08 : 0.05;
        break;
    case Article::Chaussures:
        reduc = (has_card) ? 0.18 : 0.12;
        break;
    default:
        std::cout << "How did we get here ?" << std::endl;
        return 1;
    }
    if (age < 26)
        reduc += 0.10;

    prix *=  (1 - reduc);
    float coupon = (prix * 0.10 > 30) ? 30 : prix * 0.10;
    std::cout << "Le prix de votre produit est de : " << prix << " €" << std::endl;
    std::cout << "Nous vous offrons un bon d'achat d'une valeur de " << coupon << " € pour votre prochain achat" << std::endl;
    return 0;
}
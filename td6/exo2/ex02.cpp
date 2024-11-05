#include "exo02.hpp"

int combat_turn(Pokemon& fast, Pokemon& slow, int turn)
{

        std::cout << "Tour " << turn << ":" << std::endl;
        if (slow.pv <= fast.atk)
        {
            slow.pv = 0;
            std::cout << fast.nom << " attaque, il reste 0 PV à " << slow.nom << '.' << std::endl;
            std::cout << slow.nom << "  est KO, il ne peut pas attaquer." << std::endl << std::endl;
            return 1;
        }
        else
        {
            slow.pv -= fast.atk;
            std::cout << fast.nom << " attaque, il reste " << slow.pv << " PV à " << slow.nom << '.' << std::endl;
        }
        
        if (fast.pv <= slow.atk)
        {
            fast.pv = 0;
            std::cout << slow.nom << " attaque, il reste 0 PV à " << fast.nom << '.' << std::endl << std::endl;
            return 2;
        }

        fast.pv -= slow.atk;
        std::cout << slow.nom << " attaque, il reste " << fast.pv << " PV à " << fast.nom << '.' <<std::endl << std::endl;
    return 0;
}

int combat_single(Pokemon& poke1, Pokemon& poke2, int& turn)
{
    int res;
    if (poke1.speed > poke2.speed)
    {
        while (true)
        {
            turn++;
            res = combat_turn(poke1, poke2, turn);
            if (res != 0)
            {
                return res;
            }
        }
    }
    else if (poke2.speed > poke1.speed)
    {
        while (true)
        {
            turn++;
            res = combat_turn(poke2, poke1, turn);
            if (res != 0)
            {
                return res;
            }
        }    
    }
    else
    {
        while (true)
        {
            turn++;
            if (!(rand() % 2))
            {
                res = combat_turn(poke1, poke2, turn);
            }
            else
            {
                res = combat_turn(poke2, poke1, turn);
            }
            
            if (res != 0)
            {
                return res;
            }
        }
    }
}

int combat(Pokemon poke1, Pokemon poke2)
{
    int turn = 0;
    if (poke1.pv == 0)
    {
        std::cout << poke2.nom << " gagne!" << std::endl;
        return 1;
    }
    if (poke2.pv == 0)
    {
        std::cout << poke1.nom << " gagne!" << std::endl;
        return 2;
    }    
    int res = combat_single(poke1, poke2, turn);
    if (res == 1)
    {
        std::cout << poke1.nom << " gagne!" << std::endl << std::endl;
    }
    else
    {
        std::cout << poke2.nom << " gagne!" << std::endl << std::endl; 
    }
    return res;
}

int combat(Dresseur dres1, Dresseur dres2)
{
    std::array<int, 2> ko {0, 0};
    int res;
    int turn = 0;
    while (*ko.begin() < 3 && *(ko.end() - 1) < 3)
    {
        if (dres1.pokemons.at(*ko.begin()).pv == 0)
        {
            *ko.begin() += 1;
            continue;
        }
        if (dres2.pokemons.at(*(ko.end() - 1)).pv == 0)
        {
            *(ko.end() - 1) += 1;
            continue;
        }
        res = combat_single(dres1.pokemons.at(*ko.begin()), dres2.pokemons.at(*(ko.end() - 1)), turn);
        if (res == 1)
        {
            std::cout << dres1.pokemons.at(*ko.begin()).nom << " gagne!" << std::endl << std::endl;
            *(ko.end() - 1) += 1;
        }
        else
        {
            std::cout << dres2.pokemons.at(*(ko.end() - 1)).nom << " gagne!" << std::endl << std::endl;
            *ko.begin() += 1;
        }
    }
    if (*ko.begin() == 3)
    {
        std::cout << dres2.nom << " a gagné!" << std::endl;
        return 2;
    }
    else
    {
        std::cout << dres1.nom << " a gagné!" << std::endl;
        return 1;
    }
}

int main()
{
    Pokemon pokemon1{"Poke1", 50, 10, 8};
    Pokemon pokemon2{"Poke2", 30, 20, 3};
    combat(pokemon1, pokemon2);

    Dresseur dresseur1{"Dresseur1", {
        Pokemon{"Dresseur1_Poke1", 5, 10, 8},
        Pokemon{"Dresseur1_Poke2", 5, 10, 8},
        Pokemon{"Dresseur1_Poke3", 5, 10, 8},
    }};
    Dresseur dresseur2{"Dresseur2", {
        Pokemon{"Dresseur2_Poke1", 20, 10, 3},
        Pokemon{"Dresseur2_Poke2", 20, 10, 3},
        Pokemon{"Dresseur2_Poke3", 20, 10, 3},
    }};
    combat(dresseur1, dresseur2);
    return 0;
}
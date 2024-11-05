#pragma once

#include <array>
#include <iostream>
#include <stdlib.h>

struct Pokemon
{
    std::string nom;
    unsigned int pv;
    unsigned int atk;
    unsigned int speed;
};

struct Dresseur
{
    std::string nom;
    std::array<Pokemon, 3> pokemons;
};

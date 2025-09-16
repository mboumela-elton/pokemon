//
// Created by elton on 12/09/2025.
//

#ifndef POKEMON_POKEMONATTACK_HPP
#define POKEMON_POKEMONATTACK_HPP


#include "PokemonVector.hpp"
#include "./PokemonParty.hpp"
#include <iostream>

class PokemonAttack : public PokemonParty {
private:
    static constexpr int MAX_POKEMON = 6;

public:
    PokemonAttack() = default;
    void addPokemon(Pokemon &pokemon);
};

#endif //POKEMON_POKEMONATTACK_HPP
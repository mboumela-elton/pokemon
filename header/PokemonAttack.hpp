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

private:
    static PokemonAttack * instance;
    PokemonAttack() = default;

public:
    void addPokemon(Pokemon &pokemon);
    PokemonAttack(PokemonAttack& other) = delete;
    static PokemonAttack* getInstance();
    void displayParty() const;

};

#endif //POKEMON_POKEMONATTACK_HPP
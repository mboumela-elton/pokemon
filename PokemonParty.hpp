//
// Created by elton on 12/09/2025.
//

#ifndef POKEMON_POKEMONPARTY_HPP
#define POKEMON_POKEMONPARTY_HPP
#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {

public:
    bool extractPokemon(int id);

    void displayParty() const;
    int getCount() const;
    vector<Pokemon> getPokemons() const;

};


#endif //POKEMON_POKEMONPARTY_HPP
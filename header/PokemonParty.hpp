//
// Created by elton on 12/09/2025.
//

#ifndef POKEMON_POKEMONPARTY_HPP
#define POKEMON_POKEMONPARTY_HPP
#include "./PokemonVector.hpp"

class PokemonParty : public PokemonVector {

public:
    PokemonParty() = default;
    void displayAll() = delete;
    bool addPokemon(std::string name);
    bool addPokemon(int id);
    bool extractPokemon(std::string name);
    int getCount() const;
    void displayParty() const;
    Pokemon* getPokemonById(int id) override;
    Pokemon* getPokemonByName(const std::string& name) override;
    vector<Pokemon> getPokemons();
};


#endif //POKEMON_POKEMONPARTY_HPP
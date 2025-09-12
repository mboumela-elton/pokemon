#ifndef POKEMONVECTOR_H
#define POKEMONVECTOR_H

#include <vector>
#include "Pokemon.hpp"

using std::vector;

class PokemonVector
{
protected:
    static vector<Pokemon> pokemons;

public:
    static void addPokemon(const Pokemon& pokemon);

    void displayAll() ;

    int getCount() ;
    void removePokemon(int id);
    virtual Pokemon getPokemonById(int id) = 0;
    virtual Pokemon getPokemonByName(const std::string& name) = 0;
};

#endif // POKEMONVECTOR_H

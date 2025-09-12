#ifndef POKEDEX_H
#define POKEDEX_H

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include "PokemonVector.hpp"

class Pokedex : public PokemonVector {

private:
    static Pokedex* instance;
    void loadFromCSV(const std::string& filename);
    Pokedex();

public:

    static Pokedex* getInstance();
    Pokemon clonePokemon(const std::string name) const;

    Pokemon getPokemonById(int id) override;
    Pokemon getPokemonByName(const std::string& name) override;
};

#endif // POKEDEX_H

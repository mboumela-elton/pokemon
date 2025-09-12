//
// Created by elton on 12/09/2025.
//

#ifndef POKEMON_POKEMONATTACK_HPP
#define POKEMON_POKEMONATTACK_HPP


#include "PokemonVector.hpp"
#include "PokemonParty.hpp"
#include <iostream>

class PokemonAttack : public PokemonVector {
private:
    static constexpr int MAX_POKEMON = 6;

public:
    // Créer une équipe d'attaque à partir de la PokemonParty
    void createAttackTeam(const PokemonParty& party);

    void reintegratePokemon(PokemonParty& party, int id);

    void displayAttackTeam() const;
};

#endif //POKEMON_POKEMONATTACK_HPP
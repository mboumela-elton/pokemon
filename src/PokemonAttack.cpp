//
// Created by elton on 12/09/2025.
//

#include "../header/PokemonAttack.hpp"
#include "../header/PokemonVector.hpp"
#include "../header/PokemonParty.hpp"
#include  <algorithm>

#include "./utils/ensea_log.h"

void PokemonAttack::addPokemon(Pokemon &pokemon) {
    if (pokemons.size() < MAX_POKEMON) {
    pokemons.push_back(pokemon);
        return;
    }
    std::cout << "Vous avez atteint la limite de pokemons" << std::endl;
}
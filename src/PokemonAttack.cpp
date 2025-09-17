//
// Created by elton on 12/09/2025.
//

#include "../header/PokemonAttack.hpp"
#include "../header/PokemonVector.hpp"
#include "../header/PokemonParty.hpp"
#include  <algorithm>

#include "./utils/ensea_log.h"

PokemonAttack* PokemonAttack::instance = nullptr;

PokemonAttack* PokemonAttack::getInstance() {
    if (instance == nullptr) {
        instance = new PokemonAttack();
    }
    return instance;
}

void PokemonAttack::addPokemon(Pokemon &pokemon) {
    if (pokemons.size() < MAX_POKEMON) {
    pokemons.push_back(pokemon);
        return;
    }
    std::cout << "Vous avez atteint la limite de pokemons" << std::endl;
}

void PokemonAttack::displayParty() const {
    if (pokemons.empty()) {
        ensea_logging::log_error("Aucun Pokémon dans la partie.");
        return;
    }

    ensea_logging::log_info("Pokemons de ton equipe :\n");
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
    }
}
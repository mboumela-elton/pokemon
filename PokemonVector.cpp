#include "PokemonVector.hpp"
#include <iostream>
#include <algorithm>

#include "utils/ensea_log.h"

void PokemonVector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);
}

void PokemonVector::displayAll() const {
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        // REVIEW : Previously had 2 print statements here
    }
}

int PokemonVector::getCount() {
    return pokemons.size();
}

void PokemonVector::removePokemon(int id) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [id](const Pokemon& p) {
        return p.getId() == id;
    });

    if (it != pokemons.end()) {
        pokemons.erase(it, pokemons.end());
        ensea_logging::log_debug(
            "Pokémon avec ID ", id, " a été supprimé."
        );
    } else {
        ensea_logging::log_debug(
            "Aucun Pokémon trouvé avec ID ", id, "."
        );
    }
}

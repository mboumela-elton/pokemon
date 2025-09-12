//
// Created by elton on 12/09/2025.
//

#include "PokemonParty.hpp"
#include "Pokemon.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "utils/ensea_log.h"


bool PokemonParty::extractPokemon(int id) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [id](const Pokemon& p) {
        return p.getId() == id;
    });

    if (it != pokemons.end()) {
        pokemons.erase(it, pokemons.end());
        ensea_logging::log_debug(
            "Pokémon avec ID ", id, " a été extrait."
        );
        return true;
    } else {
        ensea_logging::log_error("Aucun Pokémon trouvé avec ID ", id, ".");
        return false;
    }
}

int PokemonParty::getCount() const {
    return pokemons.size();
}

vector<Pokemon> PokemonParty::getPokemons() const {
    return pokemons;
}

void PokemonParty::displayParty() const {
    if (pokemons.empty()) {
        ensea_logging::log_error("Aucun Pokémon dans la partie.");
        return;
    }

    ensea_logging::log_debug("Pokémons dans la partie :");
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        // REVIEW : Previously had 2 print statements here
    }
}

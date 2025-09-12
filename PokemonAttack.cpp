//
// Created by elton on 12/09/2025.
//

#include "PokemonAttack.hpp"
#include "PokemonVector.hpp"
#include "PokemonParty.hpp"
#include  <algorithm>

#include "utils/ensea_log.h"

void PokemonAttack::createAttackTeam(const PokemonParty& party) {
    if (party.getCount() == 0) {
        ensea_logging::log_error("Aucun Pokémon dans la partie pour créer une équipe d'attaque.");
        return;
    }

    pokemons.clear();
    const auto& allPokemons = party.getPokemons();

    for (const auto& pokemon : allPokemons) {
        if (pokemons.size() < MAX_POKEMON) {
            pokemons.push_back(pokemon);
        } else {
            ensea_logging::log_error(
                "Équipe d'attaque pleine. Maximum de ",
                MAX_POKEMON,
                " Pokémon."
            );
            break;
        }
    }

    ensea_logging::log_debug(
        "Équipe d'attaque créée avec ",
        pokemons.size(),
        " Pokémon."
    );
}

void PokemonAttack::reintegratePokemon(PokemonParty& party, int id) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [id](const Pokemon& p) {
        return p.getId() == id;
    });

    if (it != pokemons.end()) {
        // Réintégrer le Pokémon dans la partie
        party.addPokemon(*it);
        pokemons.erase(it, pokemons.end());
        ensea_logging::log_info(
            "Pokémon avec ID ",
            id,
            " a été réintégré dans la partie."
        );
    } else {
        ensea_logging::log_error(
            "Aucun Pokémon trouvé avec ID ",
            id,
            " dans l'équipe d'attaque."
        );
    }
}

void PokemonAttack::displayAttackTeam() const {
    if (pokemons.empty()) {
        ensea_logging::log_error("Aucune équipe d'attaque formée.");
        return;
    }

    ensea_logging::log_debug("Équipe d'attaque :");
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        // REVIEW : Previously had 2 print statements here
    }
}
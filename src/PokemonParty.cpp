//
// Created by elton on 12/09/2025.
//

#include "../header/PokemonParty.hpp"
#include "../header/Pokemon.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "../header/Pokedex.hpp"
#include "./utils/ensea_log.h"

bool PokemonParty::addPokemon(std::string name) {
    Pokedex *pokedex = Pokedex::getInstance();

    Pokemon* partyPokemon = pokedex->clonePokemon(name);
    if (partyPokemon == nullptr) {
        std::cerr << "Erreur : Échec de la clonage du Pokémon " << name << "." << std::endl;
        return false; // Ajout échoué
    }

    pokemons.push_back(*partyPokemon);
    return true; // Ajout réussi
}

bool PokemonParty::addPokemon(int id) {
    Pokedex *pokedex = Pokedex::getInstance();

    std::string name = pokedex->getPokemonById(id)->getName();
    Pokemon* partyPokemon = pokedex->clonePokemon(name);
    if (partyPokemon == nullptr) {
        std::cerr << "Erreur : Échec de la clonage du Pokémon " << name << "." << std::endl;
        return false; // Ajout échoué
    }

    pokemons.push_back(*partyPokemon);
    return true; // Ajout réussi
}

bool PokemonParty::extractPokemon(std::string name) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [name](const Pokemon& p) {
        return p.getName() == name;
    });

    if (it != pokemons.end()) {
        pokemons.erase(it, pokemons.end());
        ensea_logging::log_debug(
            name, " a ete extrait."
        );
        return true;
    } else {
        ensea_logging::log_error("Aucun Pokémon trouvé du nom ", name, ".");
        return false;
    }
}

int PokemonParty::getCount() const {
    return pokemons.size();
}

void PokemonParty::displayParty() const {
    if (pokemons.empty()) {
        ensea_logging::log_error("Aucun Pokémon dans la partie.");
        return;
    }

    ensea_logging::log_debug("Pokemons dans la partie :\n");
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
    }
}

Pokemon* PokemonParty::getPokemonById(int id) {
    for (const Pokemon& pokemon : pokemons) {
        if (pokemon.getId() == id) {
            return new Pokemon(pokemon);
        }
    }
    throw std::runtime_error("Pokémon non trouvé avec l'ID " + std::to_string(id));
}

Pokemon* PokemonParty::getPokemonByName(const std::string& name) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getName() == name) {
            return new Pokemon(pokemon);
        }
    }
    throw std::runtime_error("Pokémon non trouvé avec le nom " + name);
}

vector<Pokemon> PokemonParty::getPokemons() {
    return pokemons;
}

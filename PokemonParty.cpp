//
// Created by elton on 12/09/2025.
//

#include "PokemonParty.hpp"
#include "Pokemon.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


bool PokemonParty::extractPokemon(int id) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [id](const Pokemon& p) {
        return p.getId() == id;
    });

    if (it != pokemons.end()) {
        pokemons.erase(it, pokemons.end());
        std::cout << "Pokémon avec ID " << id << " a été extrait." << std::endl;
        return true;
    } else {
        std::cout << "Aucun Pokémon trouvé avec ID " << id << "." << std::endl;
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
        std::cout << "Aucun Pokémon dans la partie." << std::endl;
        return;
    }

    std::cout << "Pokémon dans la partie :" << std::endl;
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << pokemon.getId() << " / " << pokemon.getName() << std::endl;
    }
}

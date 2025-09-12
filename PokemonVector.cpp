#include "PokemonVector.hpp"
#include <iostream>
#include <algorithm>

void PokemonVector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);
}

void PokemonVector::displayAll() {
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << pokemon.getId() << " / " << pokemon.getName() << std::endl;
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
        std::cout << "Pokémon avec ID " << id << " a été supprimé." << std::endl;
    } else {
        std::cout << "Aucun Pokémon trouvé avec ID " << id << "." << std::endl;
    }
}

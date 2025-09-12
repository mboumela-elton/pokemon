//
// Created by elton on 12/09/2025.
//

#include "PokemonAttack.hpp"
#include "PokemonVector.hpp"
#include "PokemonParty.hpp"
#include  <algorithm>

void PokemonAttack::createAttackTeam(const PokemonParty& party) {
    if (party.getCount() == 0) {
        std::cout << "Aucun Pokémon dans la partie pour créer une équipe d'attaque." << std::endl;
        return;
    }

    pokemons.clear();
    const auto& allPokemons = party.getPokemons();

    for (const auto& pokemon : allPokemons) {
        if (pokemons.size() < MAX_POKEMON) {
            pokemons.push_back(pokemon);
        } else {
            std::cout << "Équipe d'attaque pleine. Maximum de " << MAX_POKEMON << " Pokémon." << std::endl;
            break;
        }
    }

    std::cout << "Équipe d'attaque créée avec " << pokemons.size() << " Pokémon." << std::endl;
}

void PokemonAttack::reintegratePokemon(PokemonParty& party, int id) {
    auto it = std::remove_if(pokemons.begin(), pokemons.end(), [id](const Pokemon& p) {
        return p.getId() == id;
    });

    if (it != pokemons.end()) {
        // Réintégrer le Pokémon dans la partie
        party.addPokemon(*it);
        pokemons.erase(it, pokemons.end());
        std::cout << "Pokémon avec ID " << id << " a été réintégré dans la partie." << std::endl;
    } else {
        std::cout << "Aucun Pokémon trouvé avec ID " << id << " dans l'équipe d'attaque." << std::endl;
    }
}

void PokemonAttack::displayAttackTeam() const {
    if (pokemons.empty()) {
        std::cout << "Aucune équipe d'attaque formée." << std::endl;
        return;
    }

    std::cout << "Équipe d'attaque :" << std::endl;
    for (const auto& pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << pokemon.getId() << " / " << pokemon.getName() << std::endl;
    }
}
//
// Created by user on 17/09/2025.
//

#include "../header/WelcomeState.hpp"
#include "../header/ExplorationState.hpp"
#include "../header/PokemonAttack.hpp"
#include "../header/PokemonParty.hpp"
#include "utils/ensea_log.h"

void WelcomeState::enter(StateMachine* sm) {
    ensea_logging::log_info("Bienvenue dans ma version du jeu Pokemon !\n");
    ensea_logging::log_info("Veuillez entrer votre nom : ");
    std::getline(std::cin, playerName);

    PokemonParty *pokemonParty = new PokemonParty();
    for (int i=1; i<=12 ; i++) {
        pokemonParty->addPokemon(i);
    }
    pokemonParty->displayParty();

    ensea_logging::log_info("Entrer les id des pokemons que vous souhaitez : ");
    std::vector<int> indices;
    int index;

    while (std::cin >> index) {
        indices.push_back(index);
        if (std::cin.peek() == '\n') break; // Arrête à la fin de la ligne
    }

    PokemonAttack *pokemonAttack = new PokemonAttack();
    for (int i : indices)
    {
        pokemonAttack->addPokemon(*(pokemonParty->getPokemonById(i)));
    }
    std::cout << "Pokémons sélectionnés :\n";
    pokemonAttack->displayParty();

    sm->setState(new ExplorationState());
}

void WelcomeState::update(StateMachine*) {}

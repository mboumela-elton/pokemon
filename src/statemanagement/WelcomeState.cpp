//
// Created by user on 17/09/2025.
//

#include "../../header/WelcomeState.hpp"
#include "../../header/ExplorationState.hpp"
#include "../../header/PokemonAttack.hpp"
#include "../../header/PokemonParty.hpp"

void WelcomeState::enter(StateMachine* sm) {
    std::cout << "Bienvenue dans ma version du jeu Pokemon !\n";
    std::cout << "Veuillez entrer votre nom :  ";
    std::getline(std::cin, playerName);

    PokemonParty *pokemonParty = new PokemonParty();
    for (int i=1; i<=36 ; i+=3) {
        pokemonParty->addPokemon(i);
    }
    pokemonParty->displayParty();

    std::cout << "Entrer les id des pokemons que vous souhaitez : ";
    std::vector<int> indices;
    int index;

    while (std::cin >> index) {
        indices.push_back(index);
        if (std::cin.peek() == '\n') break; // Arrête à la fin de la ligne
    }

    PokemonAttack *pokemonAttack = PokemonAttack::getInstance();
    for (int i : indices)
    {
        pokemonAttack->addPokemon(*(pokemonParty->getPokemonById(i)));
    }
    pokemonAttack->displayParty();

    sm->setState(new ExplorationState());
}

void WelcomeState::update(StateMachine*) {}

//
// Created by user on 17/09/2025.
//

#include "../../header/BattleState.hpp"
#include "../../header/ExplorationState.hpp"
#include "../../header/GameOverState.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>


#include "../../header/Pokedex.hpp"
#include "../../header/PokemonAttack.hpp"


void BattleState::enter(StateMachine*) {
    std::cout << "Vous entrez dans l arene pour combattre un Pokemon !\n";
}

void BattleState::update(StateMachine* sm) {
    // Simule un combat
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int id = std::rand() % 100 + 1;
    Pokedex *pokedex = Pokedex::getInstance();
    Pokemon *pokemon = pokedex->getPokemonById(id);
    std::cout << "Vous combattez contre";
    pokemon->displayInfo();

    int index;
    std::cout << "\n Choisissez l un de vos pokemon par son id : ";
    std::cin >> index;
    PokemonAttack *pokemonAttack = PokemonAttack::getInstance();
    Pokemon *pokemon2 = pokemonAttack->getPokemonById(index);
    std::cout << pokemon2->getName() <<" est pret au combat contre " << pokemon->getName();

    while (pokemon->getHitPoint() > 0 && pokemon2->getHitPoint() > 0) {
        std::string action;
        std::cout << "\nTapez 'f' pour attaquer : ";
        std::cin >> action;

        if (action == "f") {
            pokemon2->strike(*pokemon);
        }
        if (pokemon2->getHitPoint() <= 0) break;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Petite pause

        pokemon->strike(*pokemon2);
        if (pokemon->getHitPoint() <= 0) break;
    }

    bool victoire = pokemon->getHitPoint() <= 0;
    if (victoire) {
        std::cout << "\n🎉 Vous avez gagne le combat !\n";
        sm->setState(new ExplorationState());
    } else {
        std::cout << "\n💀 Vous avez perdu le combat...\n";
        sm->setState(new GameOverState());
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

}

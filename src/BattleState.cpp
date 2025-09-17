//
// Created by user on 17/09/2025.
//

#include "../header/BattleState.hpp"
#include "../header/ExplorationState.hpp"
#include "../header/GameOverState.hpp"
#include <iostream>

void BattleState::enter(StateMachine*) {
    std::cout << "Vous entrez dans l arene pour combattre un Pokemon !\n";
}

void BattleState::update(StateMachine* sm) {
    // Simule un combat
    std::cout << "Vous combattez un Pokemon au hasard...\n";
    bool won = (rand() % 2) == 0; // Gagner ou perdre aleatoirement
    if (won) {
        std::cout << "Vous avez gagne le combat !\n";
        sm->setState(new ExplorationState());
    } else {
        std::cout << "Vous avez perdu le combat !\n";
        sm->setState(new GameOverState());
    }
}
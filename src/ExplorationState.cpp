//
// Created by user on 17/09/2025.
//

#include <iostream>

#include "../header/ExplorationState.hpp"
#include "../header/BattleState.hpp"

void ExplorationState::enter(StateMachine*) {
    std::cout << "Vous explorez la foret...\n";
}

void ExplorationState::update(StateMachine* sm) {
    std::cout << "Vous pouvez : 1. Combattre un Pok emon, 2. Explorer davantage (taper 1 ou 2) : ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        sm->setState(new BattleState());
    } else {
        std::cout << "Vous continuez à explorer...\n";
    }
}
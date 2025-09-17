//
// Created by user on 17/09/2025.
//

#include <iostream>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "../../header/ExplorationState.hpp"
#include "../../header/BattleState.hpp"

void ExplorationState::enter(StateMachine*) {
    std::cout << "\n\nVous explorez la foret...\n";
}

void ExplorationState::update(StateMachine* sm) {
    std::cout << "Vous continuez a explorer...\n";

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while (true) {
        std::cout << "...";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause de 0.5s

        // Combat déclenché aléatoirement (1 chance sur 10 à chaque tour)
        if (std::rand() % 20 == 0) {
            std::cout << "\nUn Pokemon sauvage apparait !\n";
            sm->setState(new BattleState());
            break;
        }
    }
}

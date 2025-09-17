//
// Created by user on 17/09/2025.
//

#include "../header/GameOverState.hpp"
#include "../header/ExplorationState.hpp"

void GameOverState::enter(StateMachine*) {
    std::cout << "Game Over ! Vous avez perdu.\n";
}

void GameOverState::update(StateMachine* sm) {
    std::cout << "Retour à l'exploration...\n";
    sm->setState(new ExplorationState());
}
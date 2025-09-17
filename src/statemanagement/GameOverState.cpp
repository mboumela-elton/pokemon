//
// Created by user on 17/09/2025.
//

#include "../../header/GameOverState.hpp"
#include "../../header/ExplorationState.hpp"
#include "../../header/WelcomeState.hpp"

void GameOverState::enter(StateMachine*) {
    std::cout << "Game Over ! Vous avez perdu.\n";
}

#include <iostream>

void GameOverState::update(StateMachine* sm) {
    std::cout << "\n Partie terminee.\n";
    std::cout << "Appuyez sur 'r' pour recommencer ou une autre touche pour quitter : ";

    std::string input;
    std::cin >> input;

    if (input == "r" || input == "R") {
        std::cout << "Redémarrage de la partie...\n";
        sm->setState(new WelcomeState());
    } else {
        std::cout << "Merci d'avoir joué ! À bientôt.\n";
    }
}

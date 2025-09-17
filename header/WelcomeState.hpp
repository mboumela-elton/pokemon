//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_WELCOME_HPP
#define POKEMON_WELCOME_HPP

#include "State.hpp"
#include <iostream>
#include "StateMachine.hpp"

class WelcomeState : public State {
public:
    void enter(StateMachine* sm) override;
    void update(StateMachine*) override;

private:
    std::string playerName;
};


#endif //POKEMON_WELCOME_HPP
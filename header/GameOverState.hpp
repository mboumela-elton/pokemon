//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_GAMEOVERSTATE_HPP
#define POKEMON_GAMEOVERSTATE_HPP

#include <iostream>
#include "State.hpp"
#include "StateMachine.hpp"

class GameOverState : public State {
public:
    void enter(StateMachine*) override;
    void update(StateMachine* sm) override;
};


#endif //POKEMON_GAMEOVERSTATE_HPP
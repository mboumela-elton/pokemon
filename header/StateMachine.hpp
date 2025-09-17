//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_STATEMACHINE_HPP
#define POKEMON_STATEMACHINE_HPP

#include "State.hpp"

class StateMachine {

private:
    State* currentState;

public:
    void setState(State* newState);
    void update();
};

#endif //POKEMON_STATEMACHINE_HPP
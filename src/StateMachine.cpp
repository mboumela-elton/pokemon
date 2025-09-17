//
// Created by user on 17/09/2025.
//

#include "../header/StateMachine.hpp"

State* currentState = nullptr;

void StateMachine::setState(State* newState) {
    currentState = newState;
    currentState->enter(this);
}

void StateMachine::update() {
    if (currentState) {
        currentState->update(this);
    }
}



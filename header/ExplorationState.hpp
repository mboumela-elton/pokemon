//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_EXPLORATIONSTATE_HPP
#define POKEMON_EXPLORATIONSTATE_HPP
#include "State.hpp"
#include "StateMachine.hpp"

class ExplorationState : public State {
public:
    void enter(StateMachine*) override ;
    void update(StateMachine* sm) override;
};


#endif //POKEMON_EXPLORATIONSTATE_HPP
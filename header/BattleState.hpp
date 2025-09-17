//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_BATTLESTATE_HPP
#define POKEMON_BATTLESTATE_HPP
#include "State.hpp"
#include "StateMachine.hpp"

class BattleState: public State {
public:
    void enter(StateMachine*) override;
    void update(StateMachine* sm) override;
};

#endif //POKEMON_BATTLESTATE_HPP
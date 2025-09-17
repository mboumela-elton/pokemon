//
// Created by user on 17/09/2025.
//

#ifndef POKEMON_STATE_HPP
#define POKEMON_STATE_HPP

class StateMachine;

class State
{
public:
    virtual void enter(StateMachine* sm) = 0;
    virtual void update(StateMachine* sm) = 0;
    virtual ~State() {}
};


#endif //POKEMON_STATE_HPP
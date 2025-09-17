#include <iostream>
#include <string>
#include <ctime>
#include "../header/StateMachine.hpp"
#include "../header/WelcomeState.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)));
    StateMachine sm;
    sm.setState(new WelcomeState());

    while (true) {
        sm.update();
    }

    return 0;
}
cmake_minimum_required(VERSION 3.28)
project(pokemon)

set(CMAKE_CXX_STANDARD 17)

add_executable(pokemon src/main.cpp
        src/Pokemon.cpp
        header/Pokemon.hpp
        src/PokemonVector.cpp
        header/PokemonVector.hpp
        src/Pokedex.cpp
        header/Pokedex.hpp
        src/PokemonParty.cpp
        header/PokemonParty.hpp
        src/PokemonAttack.cpp
        header/PokemonAttack.hpp
        src/utils/ensea_log.cpp
        header/State.hpp
        src/StateMachine.cpp
        header/StateMachine.hpp
        src/WelcomeState.cpp
        header/WelcomeState.hpp
        src/ExplorationState.cpp
        header/ExplorationState.hpp
        src/BattleState.cpp
        header/BattleState.hpp
        src/GameOverState.cpp
        header/GameOverState.hpp)

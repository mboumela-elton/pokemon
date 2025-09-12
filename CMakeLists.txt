cmake_minimum_required(VERSION 3.28)
project(pokemon)

set(CMAKE_CXX_STANDARD 17)

add_executable(pokemon main.cpp
        Pokemon.cpp
        Pokemon.hpp
        PokemonVector.cpp
        PokemonVector.hpp
        Pokedex.cpp
        Pokedex.hpp
        PokemonParty.cpp
        PokemonParty.hpp
        PokemonAttack.cpp
        PokemonAttack.hpp
        PokemonAttack.cpp
        PokemonAttack.hpp
        utils/ensea_log.cpp)

target_link_libraries(pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)
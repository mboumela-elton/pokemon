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
        src/PokemonAttack.cpp
        header/PokemonAttack.hpp
        src/utils/ensea_log.cpp)

target_link_libraries(pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)
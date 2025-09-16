
#include <iostream>
#include "../header/Pokedex.hpp"
#include "../header/PokemonAttack.hpp"
#include "../header/PokemonParty.hpp"

int main() {
    // Obtenez l'instance unique du Pokedex
    Pokedex* pokedex = Pokedex::getInstance();

    // Clonez un Pokémon par son ID
    try {
        Pokemon* clonedPokemon = pokedex->clonePokemon("Pikachu"); // Cloner le Pokémon avec ID 1
        std::cout << "Clone du Pokémon :" << std::endl;
        clonedPokemon->displayInfo();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Pokemon *foundPokemon = pokedex->getPokemonByName("Pikachu");
        std::cout << "Pokémon trouvé :" << std::endl;
        foundPokemon->displayInfo();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    PokemonParty *pokemonParty = new PokemonParty();
    for (int i=1; i<=80 ; i+=4) {
        pokemonParty->addPokemon(i);
    }
    pokemonParty->displayParty();

    std::cout << "Pokémon Attack:" << std::endl;
    PokemonAttack *pokemonAttack = new PokemonAttack();
    for (int i=1; i<=80 ; i+=12) {
        pokemonAttack->addPokemon(*(pokemonParty->getPokemonById(i)));
    }
    pokemonAttack->displayParty();

    return 0;
}

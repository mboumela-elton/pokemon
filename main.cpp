
#include <iostream>
#include "Pokemon.hpp"
#include "PokemonVector.hpp"
#include  "Pokedex.hpp"

int main() {
    // Pokemon pikachu(1, "Pikachu", 35.0, 55.0, 40.0, 1);
    // Pokemon bulbasaur(2, "Bulbasaur", 45.0, 49.0, 49.0, 1);
    //
    // std::cout << "Informations de Pikachu :" << std::endl;
    // pikachu.displayInfo();
    //
    // std::cout << "\nInformations de Bulbasaur :" << std::endl;
    // bulbasaur.displayInfo();
    //
    // pikachu.strike(bulbasaur);
    // bulbasaur.strike(pikachu);
    //
    // std::cout << "\nNombre de Pokemon : " << Pokemon::pokemonCount << std::endl;

    // Obtenir l'instance unique du Pokedex
    Pokedex* pokedex = Pokedex::getInstance();

    // Afficher tous les Pokémon ajoutés
    std::cout << "Liste des Pokémon dans le Pokédex :" << std::endl;
    pokedex->displayAll();


    return 0;
}
/*

#include <iostream>
#include "pokedex.hpp"

int main() {
    // Obtenez l'instance unique du Pokedex
    Pokedex* pokedex = Pokedex::getInstance();

    // Affichez tous les Pokémon dans le Pokedex
    std::cout << "Liste des Pokémon dans le Pokedex :" << std::endl;
    pokedex->displayAll();

    // Clonez un Pokémon par son ID
    try {
        Pokemon clonedPokemon = pokedex->clonePokemon(1); // Cloner le Pokémon avec ID 1
        std::cout << "Clone du Pokémon :" << std::endl;
        clonedPokemon.displayInfo();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Pokemon foundPokemon = pokedex->getPokemonByName("Pikachu");
        std::cout << "Pokémon trouvé :" << std::endl;
        foundPokemon.displayInfo();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
*/

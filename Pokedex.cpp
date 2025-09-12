#include "Pokedex.hpp"
#include "PokemonVector.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "utils/ensea_log.h"

Pokedex* Pokedex::instance = nullptr;

void Pokedex::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        ensea_logging::log_error("Erreur lors de l'ouverture du fichier ", filename);
        return;
    }

    // Ignorer l'en-tête du CSV
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, total, generation;
        std::string name, type1, type2, legendaryStr;
        double hitPoint, attack, defense, spAtk, spDef, speed;
        bool legendary;

        // Lire les champs séparés par des virgules
        if (std::getline(iss, legendaryStr, ',') && // Ignorer le premier champ (ID)
            std::getline(iss, name, ',') &&
            std::getline(iss, type1, ',') &&
            std::getline(iss, type2, ',') &&
            (iss >> total) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> hitPoint) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> attack) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> defense) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> spAtk) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> spDef) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> speed) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (iss >> generation) &&
            (iss.ignore(1)) && // Ignorer la virgule
            (std::getline(iss, legendaryStr, ','))) {

            // Convertir le champ "Legendary" en booléen
            legendary = (legendaryStr == "True");

            // Créer un Pokémon avec les informations lues
            Pokemon pokemon(id, name, hitPoint, attack, defense, generation);
            addPokemon(pokemon);
            } else {
                ensea_logging::log_error("Erreur lors de la lecture de la ligne: ", line);
                continue;
            }
    }

    file.close();
}

Pokedex::Pokedex() {
    loadFromCSV("../pokedex.csv");
}

Pokedex* Pokedex::getInstance() {
    if (instance == nullptr) {
        instance = new Pokedex();
    }
    return instance;
}

Pokemon Pokedex::clonePokemon(const std::string name) const {
      for (const auto& pokemon : pokemons) {
        if (pokemon.getName() == name) {
          return pokemon;
      }
    }
    throw std::runtime_error("Pokémon non trouvé");
}

Pokemon Pokedex::getPokemonById(int id) {
for (const auto& pokemon : pokemons) {
         if (pokemon.getId() == id) {
           return pokemon; // Retourne le Pokémon trouvé
     }
    }
    throw std::runtime_error("Pokémon non trouvé avec l'ID " + std::to_string(id));
    }

Pokemon Pokedex::getPokemonByName(const std::string& name) {
    for (const auto& pokemon : pokemons) {
        if (pokemon.getName() == name) {
            return pokemon;
        }
    }
    throw std::runtime_error("Pokémon non trouvé avec le nom " + name);
}

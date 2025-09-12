#include "Pokemon.hpp"
#include <iostream>

#include "utils/ensea_log.h"

int Pokemon::pokemonCount = 0;
Pokemon::Pokemon(int id, const std::string& name, double hitPoint, double attack, double defense, int generation)
    : id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense), generation(generation) {
}

Pokemon::Pokemon(const Pokemon& other)
    : id(other.id), name(other.name), hitPoint(other.hitPoint), attack(other.attack), defense(other.defense), generation(other.generation) {
    // std::cout << "Constructeur de recopie de " << name << std::endl;
    pokemonCount++;
}


Pokemon::~Pokemon() {
    pokemonCount--; // Decremente le compteur lors de la destruction d'un Pokemon
    // std::cout << "Destructeur appele pour " << name << std::endl;
}

void Pokemon::displayInfo() const {
    ensea_logging::log_debug(
        id,
        " | ", name,
        " | ", hitPoint,
        " | ", attack,
        " | ", defense,
        " | ", generation
    );
}

int Pokemon::getId() const { return id; }
std::string Pokemon::getName() const { return name; }
double Pokemon::getHitPoint() const { return hitPoint; }
double Pokemon::getAttack() const { return attack; }
double Pokemon::getDefense() const { return defense; }
int Pokemon::getGeneration() const { return generation; }

void Pokemon::takeDamage(double damage) {
    if (damage < 0) {
        ensea_logging::log_error("Damage was negative: ", damage);
        return;
    }

    hitPoint -= damage;
    if (hitPoint < 0) {
        hitPoint = 0;
        ensea_logging::log_info(name, " est mort !");
    }
}

void Pokemon::strike(Pokemon& target) const {
    if (attack > target.getDefense()) {
        double damage = attack - target.getDefense();
        target.takeDamage(damage);
        ensea_logging::log_debug(
            name, " attaque ", target.getName(),
            " et inflige ", damage, " degats !"
        );
        ensea_logging::log_debug(
            target.getName(), " a maintenant ",
            target.getHitPoint(), " points de vie."
        );
    } else {
        ensea_logging::log_debug(
            name, " attaque ", target.getName(),
            " mais ça ne fait pas assez de degats !"
        );
    }
}

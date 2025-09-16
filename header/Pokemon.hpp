#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using std::string;

class Pokemon {

private:
    int id;
    string name;
    double hitPoint;
    double attack;
    double defense;
    int generation;

public:
    static int pokemonCount;

    Pokemon(int id, const string& name, double hitPoint, double attack, double defense, int generation);
    Pokemon(const Pokemon& other);
    ~Pokemon();

    void displayInfo() const;
    int getId() const;
    std::string getName() const;
    double getHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    int getGeneration() const;

    void strike(Pokemon& target) const;
    void takeDamage(double damage);
};

#endif // POKEMON_H

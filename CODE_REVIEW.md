# Code review

## Code related

Issues noticed:
- Methods returning objects like Pokemon should return either pointers or references to avoid duplicates
- Pokemon::takeDamage used to not check the sign of damage (line 2)
- Previously was printing pokemons twice (fixed when implemented custom logging):
  - PokemonVector::displayAll line 3
  - PokemonParty::displayParty line 9
  - PokemonAttack::displayAttackTeam line 9
- PokemonParty::displayParty and PokemonAttack::displayAttackTeam should be replaced by an override
of the PokemonVector::displayAll method
- Some PokemonVector functions rely on id, but id is currently hardcoded to be 0:
  - PokemonVector::getPokemonById
  - PokemonParty::extractPokemon
  - PokemonAttack::reintegratePokemon
- According to the csv, pokemons with different names can have the same id, causing issues 
with the methods from previous issue
- MAX_POKEMON is better as a constexpr (PokemonAttack.hpp line 15)
- PokemonVector::displayAll is now marked as const

## Other

Issues noticed:
- Not enough folders (pokemons, main, and pokemon vectors could be in separate folders)
- Too many comments
- French comments
- No README.md
- Some code lines are too wide, like the first line of PokemonVector::removePokemon
- Getters could be marked [[nodiscard]] to help IDEs
- Repository missing .gitattributes to support OS with different end of file characters
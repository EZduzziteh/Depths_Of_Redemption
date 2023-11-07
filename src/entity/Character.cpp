#include "Character.h"

// Default constructor
Character::Character() : characterName(""), characterInventory(nullptr) {}

// Parameterized constructor (already provided)
Character::Character(Inventory *characterInventory, string characterName)
    : characterInventory(characterInventory), characterName(characterName) {}

// Getter for characterName
string Character::getCharacterName() const { return characterName; }

// Getter for characterInventory
Inventory *Character::getCharacterInventory() const {
  return characterInventory;
}

// Setter for characterName
void Character::setCharacterName(const string &name) { characterName = name; }

// Setter for characterInventory
void Character::setCharacterInventory(Inventory *inventory) {
  characterInventory = inventory;
}

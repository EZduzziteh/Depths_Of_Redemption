#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

#include "Inventory.h"

using std::string;

class Character {
 private:
  string characterName;
  Inventory *characterInventory;

 public:
  // Default constructor
  Character();

  // Parameterized constructor
  Character(Inventory *characterInventory, string characterName);

  // Getters
  string getCharacterName() const;
  Inventory *getCharacterInventory() const;

  // Setters
  void setCharacterName(const string &name);
  void setCharacterInventory(Inventory *inventory);
};

#endif  // CHARACTER_H

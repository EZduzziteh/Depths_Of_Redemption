#include "KeyItem.h"

// Default constructor
KeyItem::KeyItem() : Item(), used(false) {}

// Parameterized constructor
KeyItem::KeyItem(const std::string &name, const std::string &description,
                 const std::string &itemToBeUsedWith,
                 const std::string &itemProduced,
                 const std::string &itemProducedDescription,
                 const std::string &itemProducedToBeUsedWith)
    : Item(name, description, itemToBeUsedWith, itemProduced,
           itemProducedDescription, itemProducedToBeUsedWith),
      used(false) {}

bool KeyItem::isUsed() const { return used; }

void KeyItem::setUsed(bool value) { used = value; }

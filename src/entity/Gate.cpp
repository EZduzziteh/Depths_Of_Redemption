#include "Gate.h"

// Default constructor
Gate::Gate() : keyItem(nullptr), locked(true) {}

// Parameterized constructor that takes a KeyItem pointer
Gate::Gate(KeyItem* item) : keyItem(item), locked(true) {
  name = item->itemToBeUsedWith;
}

// override void Interactable::Interact(){
//
//
//   //this is where we unlock the gate
// }

// Checks if the gate is locked
bool Gate::isLocked() const { return locked; }

// Retrieve the key for this gate
const KeyItem* Gate::getKeyItem() const { return keyItem; }

// Set a new key for this gate (just pointing to the provided key)

void Gate::setKey(KeyItem* key) { keyItem = key; }

// Unlock the gate
void Gate::unlock() { locked = false; }

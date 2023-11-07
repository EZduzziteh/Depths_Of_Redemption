/*
 * Interactable.cpp
 *
 *  Created on: Oct. 14, 2023
 *      Author: jp
 */
#include "Interactable.h"

#include <iostream>
Interactable::Interactable() {}

Interactable::Interactable(string nam, string desc) {
  name = nam;
  description = desc;
}

Interactable::~Interactable() {}

string Interactable::getName() { return name; }
string Interactable::getDescription() { return description; }
string Interactable::getItemToBeUsedWith() { return itemToBeUsedWith; }
void Interactable::setItemToBeUsedWith(string item) { itemToBeUsedWith = item; }

void Interactable::Interact() { std::cout << "interacting"; }

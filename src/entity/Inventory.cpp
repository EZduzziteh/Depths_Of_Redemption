#include "Inventory.h"

#include <algorithm>
#include <iostream>
#include <string>

Inventory::Inventory() { items = new std::vector<Item*>(); }

Inventory::~Inventory() { delete items; }

const vector<Item*>* Inventory::GetItems() const { return items; }

bool Inventory::IsEmpty() const { return items->empty(); }

bool Inventory::ItemExists(const Item& item) const {
  return std::any_of(items->begin(), items->end(),
                     [&item](const Item* ptr) { return *ptr == item; });
}

void Inventory::AddItem(Item* item) {
  items->push_back(item);

  std::cout << "Added " << item->getItemName() << " to inventory." << std::endl;
}

void Inventory::DeleteItem(const Item& item) {
  auto it = std::remove_if(items->begin(), items->end(),
                           [&item](const Item* ptr) { return *ptr == item; });

  if (it != items->end()) {
    for (auto iter = it; iter != items->end(); ++iter) {
      delete *iter;  // Free the memory of the items being removed
    }
    items->erase(it, items->end());
  } else {
    std::cout << "Item doesn't exist in the inventory!" << std::endl;
  }
}

void Inventory::ClearInventory() { items->clear(); }

void Inventory::ShowInventory() {
  std::cout << "Inventory: ";
  if (items != nullptr) {  // Ensure items pointer is valid
    for (auto itemPtr : *items) {
      std::cout << itemPtr->getItemName() << " | ";
    }
  }
  std::cout << std::endl;
}

void Inventory::RemoveItem(int index) {
  // Check if index is within bounds
  if (index >= 0 && index < items->size()) {
    delete (*items)[index];
    items->erase(items->begin() + index);
  }
}

void Inventory::RemoveItem(std::string itemName) {
  for (auto it = items->begin(); it != items->end(); ++it) {
    if ((*it)->getItemName() == itemName) {
      delete *it;
      items->erase(it);
    }
  }
}

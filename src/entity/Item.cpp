#include "Item.h"

// Default constructor
Item::Item() : itemName(""), itemDescription("") {}

// Constructor that initializes with a name
Item::Item(const std::string &name, const std::string &description,
           const std::string &itemToBeUsedWith, const std::string &itemProduced,
           const std::string &itemProducedDescription,
           const std::string &itemProducedToBeUsedWith)
    : itemName(name),
      itemDescription(description),
      itemToBeUsedWith(itemToBeUsedWith),
      itemProduced(itemProduced),
      itemProducedDescription(itemProducedDescription),
      itemProducedToBeUsedWith(itemProducedToBeUsedWith) {}

// Destructor
Item::~Item() {}

bool Item::operator==(const Item &other) const {
  return itemName == other.itemName;
}

std::string Item::getItemName() const { return itemName; }
std::string Item::getItemDescription() const { return itemDescription; }

Item Item::ProduceItem() {
  Item item = Item(itemName, itemName, itemName, itemName, itemName, itemName);
  return item;

  // Item item = Item(itemProduced, itemProducedDescription, "",
  // itemProducedToBeUsedWith, "", "", "");
}

void Item::setItemName(const std::string &name) { itemName = name; }

void Item::setItemProduced(const std::string &name) { itemProduced = name; }

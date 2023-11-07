#ifndef SRC_ENTITY_INVENTORY_H_
#define SRC_ENTITY_INVENTORY_H_

#include <string>
#include <vector>

#include "Item.h"

using std::vector;

class Inventory {
 private:
  vector<Item*>* items;

 public:
  Inventory();
  virtual ~Inventory();

  const vector<Item*>* GetItems() const;
  void AddItem(Item* item);
  void DeleteItem(const Item& item);

  bool IsEmpty() const;
  bool ItemExists(const Item& item) const;
  void ClearInventory();
  void ShowInventory();
  void RemoveItem(int index);
  void RemoveItem(std::string itemName);
};

#endif /* SRC_ENTITY_INVENTORY_H_ */

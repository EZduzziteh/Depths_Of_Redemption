#ifndef SRC_ENTITY_ITEM_H_
#define SRC_ENTITY_ITEM_H_

#include <string>

class Item {
 private:
  std::string itemName;
  std::string itemDescription;

 public:
  Item();
  // Constructor that initializes with a name and description

  Item(const std::string &name, const std::string &description,
       const std::string &itemToBeUsedWith, const std::string &itemProduced,
       const std::string &itemProducedDescription,
       const std::string &itemProducedToBeUsedWith);
  virtual ~Item();
  bool canBeUsed = false;
  bool hasBeenUsed = false;

  // NEW PROPERTY!
  std::string itemToBeUsedWith;
  std::string itemProduced;
  std::string itemProducedDescription;
  std::string itemProducedToBeUsedWith;
  bool hasBeenPickedUp = false;
  bool operator==(const Item &other) const;

  // Getter for itemName
  std::string getItemName() const;
  // Setter for itemName
  void setItemName(const std::string &name);
  // Getter for description
  std::string getItemDescription() const;
  // Setter for item description
  void setItemDescription(const std::string &description);
  void setItemProduced(const std::string &name);
  Item ProduceItem();
};

#endif /* SRC_ENTITY_ITEM_H_ */

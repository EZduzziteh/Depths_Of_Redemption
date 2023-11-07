#ifndef KEYITEM_H
#define KEYITEM_H

#include <string>

#include "Item.h"

class KeyItem : public Item {
 private:
  bool used;  // Indicates if the key item has been used

 public:
  // Default constructor
  KeyItem();

  // Parameterized constructor
  KeyItem(const std::string &name, const std::string &description,
          const std::string &itemToBeUsedWith, const std::string &itemProduced,
          const std::string &itemProducedDescription,
          const std::string &itemProducedToBeUsedWith);

  // Returns if the key has been used
  bool isUsed() const;

  // Set the key as used or not used
  void setUsed(bool value);
};

#endif  // KEYITEM_H

#ifndef HEALTHITEM_H
#define HEALTHITEM_H

#include "Item.h"

class HealthItem : public Item {
 private:
  int healthValue;
  bool used;

 public:
  // Default constructor
  HealthItem();

  // Constructor with health value parameter
  HealthItem(int healthVal);

  // Destructor
  virtual ~HealthItem();

  // Getters
  int getHealthValue() const;
  bool isUsed() const;

  // Setters
  void setHealthValue(int value);
  void use();  // Will set 'used' to true and can have other functionalities
               // related to using the item
};

#endif  // HEALTHITEM_H

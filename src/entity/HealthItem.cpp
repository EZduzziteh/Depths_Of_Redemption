#include "HealthItem.h"

// Default constructor
HealthItem::HealthItem() : healthValue(50), used(false) {}

// Constructor with health value parameter
HealthItem::HealthItem(int healthVal) : healthValue(healthVal), used(false) {}

// Destructor
HealthItem::~HealthItem() {
  // Nothing specific to destroy here since we're not using dynamic memory
}

// Getter for healthValue
int HealthItem::getHealthValue() const { return healthValue; }

// Getter

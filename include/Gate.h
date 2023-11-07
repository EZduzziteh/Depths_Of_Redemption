#ifndef GATE_H
#define GATE_H

#include "KeyItem.h"
#include "Interactable.h"

class Gate : public Interactable{
 private:
  KeyItem* keyItem;  // Pointer to the key required to unlock this gate
  bool locked;       // Is the gate currently locked?

 public:
  // Constructors
  Gate();               // Default constructor
  Gate(KeyItem* item);  // Constructor that takes a KeyItem pointer
  bool isLocked() const;
  const KeyItem* getKeyItem() const;  // Retrieve the key for this gate
  void setKey(KeyItem* key);  // Set a new key for this gate (just assigning the
                              // pointer)
  void unlock();              // Unlocks the gate
};

#endif  // GATE_H

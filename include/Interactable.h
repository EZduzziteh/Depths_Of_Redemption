/*
 * Interactable.h
 *
 *  Created on: Oct. 14, 2023
 *      Author: sg
 */
#include <string>
using std::string;

#ifndef SRC_ENTITY_INTERACTABLE_H_
#define SRC_ENTITY_INTERACTABLE_H_

class Interactable {
 public:
  Interactable();
  Interactable(string name, string description);
  virtual ~Interactable();
  string getName();
  string getDescription();
  string getItemToBeUsedWith();
  void setItemToBeUsedWith(string item);
  virtual void Interact();

 public:
  string description;
  string name;
  string itemToBeUsedWith;
};

#endif /* SRC_ENTITY_INTERACTABLE_H_ */

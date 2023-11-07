#include "Quest.h"

// Default constructor
Quest::Quest() : questDescription(""), questComplete(false) {}

// Parameterized constructor
Quest::Quest(const string &description, const Item &item)
    : questDescription(description), questComplete(false), requiredItem(item) {}

string Quest::getQuestDescription() const { return questDescription; }

bool Quest::isQuestComplete() const { return questComplete; }

Item Quest::getRequiredItem() const { return requiredItem; }

void Quest::setQuestDescription(const string &description) {
  questDescription = description;
}

void Quest::setQuestComplete(bool complete) { questComplete = complete; }

void Quest::setRequiredItem(const Item &item) { requiredItem = item; }

bool Quest::checkCompletion(const Item &providedItem) {
  if (providedItem.getItemName() == requiredItem.getItemName()) {
    questComplete = true;
    return true;
  }
  return false;
}

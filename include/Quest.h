#ifndef QUEST_H
#define QUEST_H

#include <string>

#include "Item.h"

using std::string;

class Quest {
 private:
  string questDescription;
  bool questComplete;
  Item requiredItem;  // Item required to complete the quest

 public:
  Quest();
  Quest(const string &description, const Item &item);

  string getQuestDescription() const;
  bool isQuestComplete() const;
  Item getRequiredItem() const;

  void setQuestDescription(const string &description);
  void setQuestComplete(bool complete);
  void setRequiredItem(const Item &item);

  bool checkCompletion(const Item &providedItem);
};

#endif  // QUEST_H

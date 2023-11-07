// NPC.h
#ifndef NPC_H
#define NPC_H

#include <string>

#include "Character.h"
#include "Quest.h"

using std::string;

class NPC : public Character {
 private:
  Quest quest;
  string welcomeMessage;

 public:
  // Default constructor
  NPC();

  // Parameterized constructor
  NPC(Inventory *characterInventory, string characterName, const Quest &quest,
      const string &welcomeMessage);

  // Getter for quest
  Quest getQuest() const;

  // Setter for quest
  void setQuest(const Quest &quest);

  // Getter for welcomeMessage
  string getWelcomeMessage() const;

  // Setter for welcomeMessage
  void setWelcomeMessage(const string &message);
};

#endif  // NPC_H

#include "NPC.h"

// Default constructor
NPC::NPC() : Character(), quest(), welcomeMessage("") {}

// Parameterized constructor
NPC::NPC(Inventory *characterInventory, string characterName,
         const Quest &quest, const string &welcomeMessage)
    : Character(characterInventory, characterName),
      quest(quest),
      welcomeMessage(welcomeMessage) {}

// Getter for quest
Quest NPC::getQuest() const { return quest; }

// Setter for quest
void NPC::setQuest(const Quest &quest) { this->quest = quest; }

// Getter for welcomeMessage
string NPC::getWelcomeMessage() const { return welcomeMessage; }

// Setter for welcomeMessage
void NPC::setWelcomeMessage(const string &message) { welcomeMessage = message; }

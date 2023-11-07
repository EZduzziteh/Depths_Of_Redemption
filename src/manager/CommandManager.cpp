/**
 * @file CommandManager.cpp
 * @brief Implementation of the CommandManager class for game commands.
 * @date October 12, 2023
 * @author sg jp
 */
#include "CommandManager.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#include "Gate.h"
#include "Interactable.h"
#include "Item.h"
#include "ItemRoom.h"
#include "MovementManager.h"
#include "NPCRoom.h"
#include "PuzzleItem.h"
#include "PuzzleRoom.h"
#include "TrapRoom.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Construct a new Command Manager:: Command Manager object.
 *
 * This is the constructor for the CommandManager class.
 */
CommandManager::CommandManager() {
}  // @suppress("Class members should be properly initialized")

/**
 * @brief Destroy the Command Manager:: Command Manager object.
 *
 * This is the destructor for the CommandManager class.
 */
CommandManager::~CommandManager() {}

/**
 * @brief Get and execute user commands.
 *
 * This function captures and processes user commands. It takes user input,
 * splits it into command and subjects, and then executes the appropriate
 * action based on the command.
 */
void CommandManager::GetCommand() {
  string command = "";
  string subject1 = "";
  string subject2 = "";

  cout << "Enter a command: " << endl;
  string cmd;
  getline(cin, cmd);
  std::string delimiter = " ";
  size_t pos = 0;
  std::string token;

  // Split the input into command and subjects
  while ((pos = cmd.find(delimiter)) != std::string::npos) {
    token = cmd.substr(0, pos);

    if (command == "") {
      command = token;
    } else if (subject1 == "") {
      subject1 = token;
    } else if (subject2 == "") {
      subject2 = token;
    }

    // ignore any additional subjects or commands for now.

    cmd.erase(0, pos + delimiter.length());
  }

  // Handle the final case where the last subject or command is in 'cmd'

  if (command == "") {
    command = cmd;
    Command c = StringToCommand(command);
    ExecuteCommand(c);
  } else if (subject1 == "") {
    subject1 = cmd;
    Command c = StringToCommand(command);
    ExecuteCommand(c, subject1);
  } else if (subject2 == "") {
    subject2 = cmd;
    Command c = StringToCommand(command);
    ExecuteCommand(c, subject1, subject2);
  }
  // ignore any additional inputs

  // std::cout << "command: " << command << std::endl;
  // std::cout << "subject1: " << subject1 << std::endl;
  // std::cout << "subject2: " << subject2 << std::endl;
}

/**
 * @brief Convert a string command to a Command enum.
 *
 * @param cmd The string representation of the command.
 * @return Command The corresponding Command enum value.
 */
CommandManager::Command CommandManager::StringToCommand(string cmd) {
  // std::cout<<"command to convert: "<<cmd<<endl;
  if (cmd == "move") {
    return move;
  } else if (cmd == "use") {
    return use;
  } else if (cmd == "examine") {
    return examine;
  } else if (cmd == "help") {
    return help;
  } else if (cmd == "pickup") {
    return pickup;
  } else if (cmd == "talk") {
    return talk;
  } else if (cmd == "answer") {
    return answer;
  } else if (cmd == "give") {
    return give;
  } else if (cmd == "quit") {
    return quit;
  } else if (cmd == "inventory") {
    return inventory;
  } else if (cmd == "unlock") {
    return unlock;
  } else {
    return unknown;
  }
}

/**
 * @brief Execute a command with no subjects.
 *
 * @param cmd The command to execute.
 */
void CommandManager::ExecuteCommand(Command cmd) {
  switch (cmd) {
    case move:
      Move();
      break;

    case use:
      Use();
      break;

    case examine:
      Examine();
      break;

    case help:
      Help();
      break;

    case unlock:
      Unlock();
      break;

    case pickup:
      PickUp();
      break;

    case inventory:
      Inventory();
      break;

    case talk:
      Talk();
      break;

    case answer:
      Answer();
      break;
    case give:
      Give();
      break;

    case quit:
      std::cout << "Thank you for playing. Goodbye.";
      exit(0);  // Exits the program
      break;

    case unknown:
      std::cout << "Command Unknown! Try typing help to get a list of commands!"
                << endl;
      break;
    default:
      std::cout << "I am not sure what that command was!" << endl;
      break;
  }
}

/**
 * @brief Execute a command with one subject.
 *
 * @param cmd The command to execute.
 * @param subject1 The first subject.
 */
void CommandManager::ExecuteCommand(Command cmd, string subject1) {
  switch (cmd) {
    case move:
      Move(subject1);
      break;

    case use:
      Use(subject1);
      break;

    case examine:
      Examine(subject1);
      break;

    case help:
      Help();
      break;

    case pickup:
      PickUp(subject1);
      break;

    case quit:
      std::cout << "Thank you for playing. Goodbye.";
      exit(0);  // Exits the program
      break;
    case talk:
      Talk(subject1);
      break;
    case answer:
      Answer(subject1);
      break;

    case unlock:
      Unlock(subject1);
      break;

    case inventory:
      Inventory();
      break;

    case unknown:
      std::cout << "Command Unknown! Try typing help to get a list of commands!"
                << endl;
      break;

    default:
      std::cout << "I am not sure what that command was!" << endl;
      break;
  }
}

/**
 * @brief Execute a command with two subjects.
 *
 * @param cmd The command to execute.
 * @param subject1 The first subject.
 * @param subject2 The second subject.
 */
void CommandManager::ExecuteCommand(Command cmd, string subject1,
                                    string subject2) {
  switch (cmd) {
    case move:
      Move(subject1);  // move only takes 1 subject so we ignore the additional
                       // one
      break;
    case use:
      Use(subject1, subject2);
      break;

    case examine:
      Examine(subject1);  // only examine the first item that is input
      break;

    case help:
      Help();
      break;

    case pickup:  // only pickup first object that is input
      PickUp(subject1);
      break;

    case inventory:
      Inventory();
      break;
    case give:
      Give(subject1, subject2);
      break;

    case quit:
      std::cout << "Thank you for playing. Goodbye.";
      exit(0);  // Exits the program
      break;

    case unknown:
      std::cout << "Command Unknown! Try typing help to get a list of commands!"
                << endl;
      break;

    default:
      std::cout << "I am not sure what that command was!" << endl;
      break;
  }
}

/**
 * @brief Display a list of available commands.
 *
 * This function displays a list of available commands to the user.
 */
void CommandManager::Help() {
  cout << "This game is played by typing commands into the command line and "
          "pressing enter."
       << endl
       << "available commands: help, use, move, pickup, examine, inventory, "
          "pickup, talk, answer, give, unlock, quit"
       << endl
       << "sample command: move east" << endl;
}

/**
 * @brief Explain how the 'PickUp' command works.
 *
 * This function provides an explanation of how the 'PickUp' command works.
 */
void CommandManager::PickUp() {
  cout << "The pickup command can be used to add items to the players "
          "inventory ex) pickup orb"
       << endl;
}

/**
 * @brief Attempt to pick up an item in the current room.
 *
 * @param subject1 The name of the item to pick up.
 */
void CommandManager::PickUp(string subject1) {
  // check if the current room is an item room

  if (dynamic_cast<ItemRoom *>(player->getCurrentRoom()) == nullptr) {
    // if not an item room, then there is nothing to pick up here
    std::cout << "There are no items to pick up in this room." << endl;
    return;
  } else {
    // Check if the item exists in the room and its name matches the desired
    // item's name
    if (dynamic_cast<ItemRoom *>(player->getCurrentRoom())
                ->getRoomItem()
                ->getItemName() == subject1 &&
        dynamic_cast<ItemRoom *>(player->getCurrentRoom())
                ->getRoomItem()
                ->hasBeenPickedUp == false) {
      // Add the key item to the player's inventory
      player->getCharacterInventory()->AddItem(
          dynamic_cast<ItemRoom *>(player->getCurrentRoom())->getRoomItem());

      // cout << player->getCharacterInventory()->GetItems()->size() << endl;
      //  Optionally, if you want to remove the item from the room after picking
      //  it up:
      //  room->setRoomItem(nullptr);
      dynamic_cast<ItemRoom *>(player->getCurrentRoom())
          ->getRoomItem()
          ->hasBeenPickedUp = true;

    } else {
      std::cout << "There is no " << subject1 << " to pick up here!" << endl;
    }
  }
}

/**
 * @class CommandManager
 * @brief Manages and handles various in-game commands for a text-based
 * adventure or role-playing game.
 */

/**
 * @brief Displays a general description of the 'examine' command.
 */
void CommandManager::Examine() {
  cout << "The examine command can be used on almost anything, it will give "
          "you a description of whatever subject you give it or it can just "
          "provide a description of the room you are currently in. ex) examine "
          "pedestal,examine room"
       << endl;
}

/**
 * @brief Provides detailed information about a specified subject or the current
 * room.
 * @param subject1 The subject or item to examine.
 */
void CommandManager::Examine(string subject1) {
  if (subject1 == "room") {
    std::cout << player->getCurrentRoom()->getRoomDescription() << endl;
    if (dynamic_cast<PuzzleRoom *>(player->getCurrentRoom()) !=
        nullptr) {  // if room is a puzzle room
      if (dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
              ->getRoomPuzzle()
              ->getPuzzleRiddle() != nullptr) {
        std::cout << dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getPuzzleRiddle()
                         ->getRiddleInfo();
      }
    }
  } else {  // subject not room
    // search players inventory for item
    for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
         i++) {
      if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
          subject1) {
        std::cout << "You examine " << subject1 << ": "
                  << player->getCharacterInventory()
                         ->GetItems()
                         ->at(i)
                         ->getItemDescription()
                  << endl;
        // item = player->getCharacterInventory()->GetItems()->at(i);
        return;
      }
    }

    // if item was not found, check if item in room

    if (dynamic_cast<ItemRoom *>(player->getCurrentRoom()) !=
        nullptr) {  // If the current room is an ItemRoom
      KeyItem *keyItemInRoom =
          dynamic_cast<ItemRoom *>(player->getCurrentRoom())->getRoomItem();
      if (keyItemInRoom && keyItemInRoom->getItemName() == subject1) {
        std::cout << "You examine " << subject1 << ", "
                  << keyItemInRoom->getItemDescription() << endl;
      } else {
        std::cout << "There is no " << subject1 << " here." << endl;
      }
    } else {
      std::cout << "There is no " << subject1 << " here." << endl;
    }
  }
}

/**
 * @brief Displays a general description of the 'use' command.
 */
void CommandManager::Use() {
  cout << "The use command allows you to interact with an object. ex) use "
          "lever or ex) use torch firepit "
       << endl;
}

/**
 * @brief Allows the player to use a specified item from their inventory.
 * @param subject1 The name of the item to use.
 */
void CommandManager::Use(string subject1) {
  // search players inventory for item
  Item *item = new Item();

  if (player->getCharacterInventory()->GetItems()->size() > 0) {
    bool foundSubject1 = false;
    int itemIndex = 0;
    for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
         i++) {
      if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
          subject1) {
        foundSubject1 = true;
        // item = player->getCharacterInventory()->GetItems()->at(i);
        itemIndex = i;
      }
    }

    if (foundSubject1) {
      if (item->canBeUsed) {
        cout << "using " << subject1 << endl;
        player->getCharacterInventory()
            ->GetItems()
            ->at(itemIndex)
            ->hasBeenUsed = true;
      } else {
        cout << subject1 << "doesn't do anything" << endl;
      }

    } else {
      cout << "Item not found " << endl;
    }

  } else {
    cout << "nothing in player inventory!" << endl;
  }
}

/**
 * @brief Allows the player to use one item with another.
 * @param subject1 The first item.
 * @param subject2 The second item or interactable object.
 */
void CommandManager::Use(string subject1, string subject2) {
  // if we try to interact the same item with itself,
  if (subject1 == subject2) {
    // just call the one parameter use!
    Use(subject1);
  }

  // search player inventory for subjects 1 and 2
  bool foundSubject1 = false;
  bool foundSubject2 = false;
  bool foundSubject3 = false;
  Item *item;
  Interactable interactable;
  Item *item2;
  // search for item 1
  for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
       i++) {
    if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
        subject1) {
      foundSubject1 = true;
      item = player->getCharacterInventory()->GetItems()->at(i);
    }
  }
  // search for interactable 1

  for (int i = 0; i < player->getCurrentRoom()->interactables->size(); i++) {
    if (player->getCurrentRoom()->interactables->at(i).getName() == subject2) {
      foundSubject2 = true;
      interactable = player->getCurrentRoom()->interactables->at(i);
    }
  }

  if (foundSubject2 == false) {
    /// if we didnt find an interactable, search for an item instead!
    for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
         i++) {
      if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
          subject2) {
        foundSubject3 = true;
        item2 = player->getCharacterInventory()->GetItems()->at(i);
      }
    }
  }

  if (foundSubject1 && foundSubject2) {
    if (interactable.getItemToBeUsedWith() == item->getItemName()) {
      // dynamic_cast<ItemRoom*>(player->getCurrentRoom());
      // dynamic_cast<PuzzleItem*>(item)->
      // remove the item form player inventory<
      cout << "using " << subject1 << " with " << subject2 << endl;

      if (dynamic_cast<PuzzleRoom *>(player->getCurrentRoom()) != nullptr) {
        player->getCharacterInventory()->AddItem(
            new Item(dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->getItemName(),
                     dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->getItemDescription(),
                     dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->itemToBeUsedWith,
                     dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->itemProduced,
                     dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->itemProducedDescription,
                     dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                         ->getRoomPuzzle()
                         ->getRewardItem()
                         ->itemProducedToBeUsedWith));  //

      } else {
        interactable.Interact();
      }

    } else {
      cout << "using " << subject1 << " with " << subject2 << " does nothing!"
           << endl;
    }

  } else if (foundSubject1 && foundSubject3) {
    // when 2 items are combined, produce new item based on
    std::cout << "Combined " << subject1 << " with " << subject2
              << " creating a " << item2->itemProduced << endl;

    player->getCharacterInventory()->AddItem(

        new Item(item2->itemProduced, item2->itemProducedDescription,
                 item2->itemProducedToBeUsedWith, "occult-key",
                 "a key that unlocks the *occult-gate*", "occult-gate"));

    player->getCharacterInventory()->RemoveItem(foundSubject1);
    player->getCharacterInventory()->RemoveItem(foundSubject2);

  } else {
    cout << "invalid subjects" << endl;
  }
}

/**
 * @brief Displays a general description of the 'move' command.
 */
void CommandManager::Move() {
  std::cout << "The move command allows the player to traverse the map by "
               "moving in a cardinal direction. ex)move east"
            << endl;
}

/**
 * @brief Moves the player in a specified direction if possible.
 * @param direction The direction in which the player wants to move.
 */
void CommandManager::Move(string direction) {
  // check if we are allowed to move to the desired direction
  if (MovementManager::movePlayerInDirection(player, direction)) {
    // if the move is successful
    cout << "You moved " << direction << endl;
    //  std::cout<<player->getCurrentRoom()->getRoomDescription()<<endl;

    if (dynamic_cast<TrapRoom *>(player->getCurrentRoom()) !=
        nullptr) {  // if room is a trap room
      if (dynamic_cast<TrapRoom *>(player->getCurrentRoom())->trapIsActive()) {
        // get the room description
        std::cout << player->getCurrentRoom()->getRoomDescription() << endl;
        // get the riddle
        Trap trap =
            dynamic_cast<TrapRoom *>(player->getCurrentRoom())->getRoomTrap();

        std::cout << trap.getTrapRiddle().getRiddleInfo() << endl;

        bool alive = true;
        string answer;
        std::cout << "You must answer the riddle to live: ";
        std::cin >> answer;
        alive = TrapRiddleChecker(trap.getTrapRiddle(), answer);

        if (!alive) {
          cout << trap.getTrapDeathMessage() << "\n";
          cout << "YOU DIED!!! Thank you for playing.";

          exit(0);
        }

        if (player->getCurrentRoom()->isLastRoom()) {
          cout << "Thank you for playing you have completed the game";
          exit(0);
        } else {
          cout << "Congratulations, your answer was correct. Trap is no longer "
                  "active."
               << endl;
          dynamic_cast<TrapRoom *>(player->getCurrentRoom())
              ->setTrapActive(false);

          cin.ignore(std::numeric_limits<std::streamsize>::max(),
                     '\n');  // Clears buffer after getting the command
        }

      } else {
        std::cout << "The trap here is no longer active." << endl;
      }
    }
  } else {
    // move not successful
    cout << "Invalid Direction" << endl;
  }
}

/**
 * @brief Displays a general description of the 'talk' command.
 */
void CommandManager::Talk() {
  cout << "The talk command allows you to talk to an entity capable of speech "
          "ex) 'talk rigamort'"
       << endl;
}

/**
 * @brief Enables the player to talk to a specified entity in the room.
 * @param subject1 The entity or NPC to talk to.
 */
void CommandManager::Talk(string subject1) {
  // if in an npc room
  if (dynamic_cast<NPCRoom *>(player->getCurrentRoom()) != nullptr) {
    if (subject1 == "sage" || subject1 == "person") {
      // get welcome message
      std::cout << dynamic_cast<NPCRoom *>(player->getCurrentRoom())
                       ->getResidentNPC()
                       ->getWelcomeMessage();
      // since npc introduces themselves, update the room description to
      // include the npc name.
      player->getCurrentRoom()->setRoomDescription(
          player->getCurrentRoom()->getRoomDescription() +
          "You know the person here is named *" +
          dynamic_cast<NPCRoom *>(player->getCurrentRoom())
              ->getResidentNPC()
              ->getCharacterName() +
          "*");
      // if name matches subject 1, then execute their quest
    } else if (dynamic_cast<NPCRoom *>(player->getCurrentRoom())
                   ->getResidentNPC()
                   ->getCharacterName() == subject1) {
      // play npc welcome message
      std::cout << dynamic_cast<NPCRoom *>(player->getCurrentRoom())
                       ->getResidentNPC()
                       ->getQuest()
                       .getQuestDescription();

      // or if a generic person, or someone the player hasn't met yet, just
      // prin the welcome message.
    } else {
      std::cout << "nobody named " << subject1 << " in this room" << endl;
    }
  } else {
    std::cout << "There is nobody to talk to here!" << endl;
  }

  // if player has item to complete npc quest, complete quest, otherwise play
  // default dialog.
}

/**
 * @brief Displays a general description of the 'answer' command.
 */
void CommandManager::Answer() {
  cout << "The answer command can be used to answer riddles that npcs or "
          "specific rooms might have! knowing how to answer riddles could "
          "save "
          "your life!"
       << "ex) riddle: what gets bigger the more you take away?  'answer "
          "hole' "
       << endl;
}

/**
 * @brief Allows the player to provide an answer to a riddle or question.
 * @param subject1 The player's answer.
 */
void CommandManager::Answer(string subject1) {
  // in this case, subject 1 is the answer the play is giving to the riddle,
  // so...

  if (dynamic_cast<PuzzleRoom *>(player->getCurrentRoom()) !=
      nullptr) {  // if the room is a puzzle room
    if (subject1 == dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
                        ->getRoomPuzzle()
                        ->getPuzzleRiddle()
                        ->getRiddleAnswer()) {
      cout << "you answered correctly!" << endl;
      player->getCharacterInventory()->AddItem(
          dynamic_cast<PuzzleRoom *>(player->getCurrentRoom())
              ->getRoomPuzzle()
              ->getRewardItem());
    } else {
      cout << "that is incorrect!" << endl;
    }

  } else {
    std::cout << "There is nothing to answer here!" << endl;
  }
}

/**
 * @brief Displays the contents of the player's inventory.
 */
void CommandManager::Inventory() {
  if (player->getCharacterInventory() != nullptr) {
    player->getCharacterInventory()->ShowInventory();
  } else {
  }
}

/**
 * @brief Displays a general description of the 'give' command.
 */
void CommandManager::Give() {
  std::cout << "The give command can be used to give items to people, such as "
               "for turning items in for quests. ex) 'give sword knight' or "
               "'give torch adventurer' "
            << endl;
}

/**
 * @brief Allows the player to give a specified item to an entity.
 * @param subject1 The item to give.
 * @param subject2 The entity or NPC to give the item to.
 */
void CommandManager::Give(string subject1, string subject2) {
  // check if npc room
  if (dynamic_cast<NPCRoom *>(player->getCurrentRoom()) != nullptr) {
    // first check if subject 1 is an item in the players inventory
    bool gaveItemSuccessfully = false;

    for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
         i++) {
      if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
          subject1) {
        if (dynamic_cast<NPCRoom *>(player->getCurrentRoom())
                ->getResidentNPC()
                ->getQuest()
                .getRequiredItem()
                .getItemName() ==
            player->getCharacterInventory()->GetItems()->at(i)->getItemName()) {
          // have npc add the item to the player inventory
          player->getCharacterInventory()->AddItem(new Item(
              player->getCharacterInventory()->GetItems()->at(i)->itemProduced,
              player->getCharacterInventory()
                  ->GetItems()
                  ->at(i)
                  ->itemProducedDescription,
              player->getCharacterInventory()
                  ->GetItems()
                  ->at(i)
                  ->itemProducedToBeUsedWith,
              "null", "null", "null"));
          // std::cout<<"used
          // with:"<<player->getCharacterInventory()->GetItems()->at(i)->itemProducedToBeUsedWith;
          player->getCharacterInventory()->RemoveItem(i);
          // player->characterInventory->GetItems()->(player->getCharacterInventory()->GetItems()->at(i));
          // display feedback message
          std::cout
              << "Thanks for completing my quest! good luck on your adventure!"
              << std::endl;
          gaveItemSuccessfully = true;
          break;
        }
      }
    }

    if (!gaveItemSuccessfully) {
      std::cout << "couldn't give " << subject1 << " to " << subject2 << endl;
    }
  } else {
    std::cout << "There is nobody to give anything to here!" << endl;
  }
}

/**
 * @brief Displays a general description of the 'unlock' command.
 */
void CommandManager::Unlock() {
  std::cout << "the unlock command can be used to unlock gates encountered in "
               "the dungeon! ex) unlock iron-gate"
            << endl;
}

/**
 * @brief Attempts to unlock a specified object or gate.
 * @param subject1 The object or gate to unlock.
 */
void CommandManager::Unlock(string subject1) {
  if (player->getCurrentRoom()->northGate != nullptr) {
    // check if right gate
    if (subject1 == player->getCurrentRoom()->northGate->getName()) {
      // check if player has key
      for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
           i++) {
        if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
            player->getCurrentRoom()->northGate->itemToBeUsedWith) {
          player->getCurrentRoom()->northGate->unlock();
          std::cout << "unlocked gate!" << endl;
          player->getCharacterInventory()->RemoveItem(i);
          return;
        }
      }
      std::cout << "You dont have the required key!" << endl;
      return;
    }
  }

  if (player->getCurrentRoom()->southGate != nullptr) {
    // check if right gate
    if (subject1 == player->getCurrentRoom()->southGate->getName()) {
      // check if player has key
      for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
           i++) {
        if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
            player->getCurrentRoom()->southGate->itemToBeUsedWith) {
          player->getCurrentRoom()->southGate->unlock();
          std::cout << "unlocked gate!" << endl;
          player->getCharacterInventory()->RemoveItem(i);
          return;
        }
      }
      std::cout << "You dont have the required key!" << endl;
      return;
    }
  }
  if (player->getCurrentRoom()->eastGate != nullptr) {
    // check if right gate
    if (subject1 == player->getCurrentRoom()->eastGate->getName()) {
      // check if player has key
      for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
           i++) {
        if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
            player->getCurrentRoom()->eastGate->itemToBeUsedWith) {
          player->getCurrentRoom()->eastGate->unlock();
          std::cout << "unlocked gate!" << endl;
          player->getCharacterInventory()->RemoveItem(i);
          return;
        }
      }
      std::cout << "You dont have the required key!" << endl;
      return;
    }
  }
  if (player->getCurrentRoom()->westGate != nullptr) {
    // check if right gate
    if (subject1 == player->getCurrentRoom()->westGate->getName()) {
      // check if player has key
      for (int i = 0; i < player->getCharacterInventory()->GetItems()->size();
           i++) {
        if (player->getCharacterInventory()->GetItems()->at(i)->getItemName() ==
            player->getCurrentRoom()->westGate->itemToBeUsedWith) {
          player->getCurrentRoom()->westGate->unlock();
          std::cout << "unlocked gate!" << endl;
          player->getCharacterInventory()->RemoveItem(i);
          return;
        }
      }
      std::cout << "You dont have the required key!" << endl;
      return;
    }
  }
  cout << "no " << subject1 << " to unlock here" << endl;
}

/**
 * @brief Checks if the player's answer to a trap riddle is correct.
 * @param riddle The riddle posed by the trap.
 * @param answer The player's answer to the riddle.
 * @return Returns true if the answer is correct, false otherwise.
 */
bool CommandManager::TrapRiddleChecker(Riddle riddle, string answer) {
  if (riddle.getRiddleAnswer() == answer) {
    return true;
  }

  return false;
}

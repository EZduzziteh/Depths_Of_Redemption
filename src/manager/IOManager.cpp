/**
 * @file IOManager.cpp
 * @brief Implementation of the IOManager class for moving room to room.
 * @date October 12, 2023
 * @author sg, jp
 */

#include "IOManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Gate.h"
#include "ItemRoom.h"
#include "KeyItem.h"
#include "NPCRoom.h"
#include "PuzzleRoom.h"
#include "Room.h"
#include "TrapRoom.h"

/**
 * @brief Default constructor for IOManager.
 */
IOManager::IOManager() {}

/**
 * @brief Generate a game map from a file.
 *
 * @return A pointer to the loaded map.
 */
Map* IOManager::generateMapFromFile() {
  std::ifstream roomFile(roomsFileLocation);
  std::string line;
  std::vector<Room*> loadedRooms;

  while (std::getline(roomFile, line)) {
    std::istringstream iss(line);
    int roomType;
    iss >> roomType;
    char semicolon;  // For discarding the delimiter
    iss >> semicolon;

    Room* room = nullptr;
    switch (roomType) {
      case 0:
        room = createBasicRoom(iss);
        break;
      case 1:
        room = createItemRoom(iss);
        break;
      case 2:
        room = createNPCRoom(iss);
        break;
      case 3:
        room = createPuzzleRoom(iss);
        break;
      case 4:
        room = createTrapRoom(iss);
        break;
    }

    if (room) {
      loadedRooms.push_back(room);
    }
  }

  Map* map = new Map();
  if (!loadedRooms.empty()) {
    map->setStartingRoom(loadedRooms.front());
    map->setLastRoom(loadedRooms.back());
    loadedRooms.back()->setLastRoom(true);
  }

  loadConnections(map, &loadedRooms);

  return map;
}

/**
 * @brief Create a basic room from a given input stream.
 *
 * @param iss The input stream containing the room data.
 * @return A pointer to the newly created room.
 */
Room* IOManager::createBasicRoom(std::istringstream& iss) {
  std::string roomNumberStr, roomName, roomDescription;
  std::getline(iss, roomNumberStr, ';');
  std::getline(iss, roomName, ';');
  std::getline(iss, roomDescription, ';');

  unsigned roomNumber = std::stoi(roomNumberStr);

  return new Room(roomNumber, roomName, roomDescription);
}

/**
 * @brief Create an item room from a given input stream.
 *
 * @param iss The input stream containing the item room data.
 * @return A pointer to the newly created item room.
 */
ItemRoom* IOManager::createItemRoom(std::istringstream& iss) {
  std::string roomNumberStr, roomName, roomDescription, itemName,
      itemDescription, itemToBeUsedWith, itemProduced, itemProducedDescription,
      itemProducedToBeUsedWith;
  std::getline(iss, roomNumberStr, ';');
  std::getline(iss, roomName, ';');
  std::getline(iss, roomDescription, ';');
  std::getline(iss, itemName, ';');
  std::getline(iss, itemDescription, ';');
  std::getline(iss, itemToBeUsedWith, ';');
  std::getline(iss, itemProduced, ';');
  std::getline(iss, itemProducedDescription, ';');
  std::getline(iss, itemProducedToBeUsedWith, ';');
  unsigned roomNumber = std::stoi(roomNumberStr);

  KeyItem* keyItem =
      new KeyItem(itemName, itemDescription, itemProduced, itemToBeUsedWith,
                  itemProducedDescription, itemProducedToBeUsedWith);
  keyItem->canBeUsed = false;

  return new ItemRoom(roomNumber, roomName, roomDescription, false, false,
                      nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                      nullptr, nullptr, keyItem);
}

/**
 * @brief Create an NPC room from a given input stream.
 *
 * @param iss The input stream containing the NPC room data.
 * @return A pointer to the newly created NPC room.
 */
NPCRoom* IOManager::createNPCRoom(std::istringstream& iss) {
  std::string roomNumberStr, roomName, roomDescription, npcName, welcomeMessage,
      hasQuestStr, questDescription, requiredItemName, requiredItemDescription,
      requiredItemToBeUsedWith, requiredItemProduced,
      requiredItemProducedDescription, requiredItemProducedToBeUsedWith;

  // Extract the fields using the `;` delimiter
  std::getline(iss, roomNumberStr, ';');
  std::getline(iss, roomName, ';');
  std::getline(iss, roomDescription, ';');
  std::getline(iss, npcName, ';');
  std::getline(iss, welcomeMessage, ';');
  std::getline(iss, hasQuestStr, ';');

  unsigned roomNumber =
      std::stoi(roomNumberStr);           // Convert string to unsigned int
  int hasQuest = std::stoi(hasQuestStr);  // Convert string to int

  Inventory* defaultInventory =
      new Inventory();  // Create a default empty inventory for NPC

  NPC* newNPC;  // Declare the newNPC variable here

  if (hasQuest) {
    std::getline(iss, questDescription, ';');
    std::getline(iss, requiredItemName, ';');
    std::getline(iss, requiredItemDescription, ';');
    std::getline(iss, requiredItemToBeUsedWith, ';');
    std::getline(iss, requiredItemProduced, ';');
    std::getline(iss, requiredItemProducedDescription, ';');
    std::getline(iss, requiredItemProducedToBeUsedWith, ';');
    // Create the Item for the Quest
    Item requiredItem(requiredItemName, requiredItemDescription,
                      requiredItemToBeUsedWith, requiredItemProduced,
                      requiredItemProducedDescription,
                      requiredItemProducedToBeUsedWith);

    // Create the Quest
    Quest npcQuest(questDescription, requiredItem);

    int hasKey;
    std::string keyName, keyDescription, keyProduced, keyToBeUsedWith,
        keyProducedDescription, keyProducedToBeUsedWith;
    iss >> hasKey;  // Read whether the NPC has a key

    if (hasKey) {
      std::getline(iss, keyName, ';');
      std::getline(iss, keyDescription, ';');
      std::getline(iss, keyProduced, ';');
      std::getline(iss, keyToBeUsedWith, ';');
      std::getline(iss, keyProducedDescription, ';');
      std::getline(iss, keyProducedToBeUsedWith, ';');
      KeyItem* npcKeyItem =
          new KeyItem(keyName, keyDescription, keyProduced, keyToBeUsedWith,
                      keyProducedDescription, keyProducedToBeUsedWith);
      defaultInventory->AddItem(npcKeyItem);
    }

    // Create the NPC with the Quest
    newNPC = new NPC(defaultInventory, npcName, npcQuest, welcomeMessage);

  } else {
    // If no quest, just create the NPC with the default inventory and no quest
    newNPC = new NPC(defaultInventory, npcName, Quest(), welcomeMessage);
  }

  iss.ignore();
  // Create and return the NPCRoom
  return new NPCRoom(roomNumber, roomName, newNPC, roomDescription);
}

/**
 * @brief Create a puzzle room from a given input stream.
 *
 * @param iss The input stream containing the puzzle room data.
 * @return A pointer to the newly created puzzle room.
 */
PuzzleRoom* IOManager::createPuzzleRoom(std::istringstream& iss) {
  unsigned roomNumber;
  std::string roomName, roomDescription, puzzleInformation,
      puzzleSpecificItemName, rewardItemName, rewardItemDescription, riddleInfo,
      riddleAnswer, roomNumberDesc, rewardItemToBeUsedWith, rewardItemProduced,
      rewardItemProducedDescription, rewardItemProducedtoBeUsedWith;
  int hasPuzzleItem, hasRiddle;

  // const std::string &itemProduced,
  // const std::string &itemProducedDescription, const std::string
  // &itemProducedToBeUsedWith

  // Extract the fields using the `;` delimiter
  std::getline(iss, roomNumberDesc, ';');
  roomNumber = std::stoi(roomNumberDesc);
  std::getline(iss, roomName, ';');
  std::getline(iss, roomDescription, ';');
  std::getline(iss, puzzleInformation, ';');
  std::getline(iss, rewardItemName, ';');
  std::getline(iss, rewardItemDescription, ';');
  std::getline(iss, rewardItemToBeUsedWith, ';');
  std::getline(iss, rewardItemProduced, ';');
  std::getline(iss, rewardItemProducedDescription, ';');
  std::getline(iss, rewardItemProducedtoBeUsedWith, ';');

  iss >> hasPuzzleItem;
  iss.ignore();  // skip the semicolon or newline after the flag

  std::string itemDescription, puzzleCompleteDesc, puzzleIncompleteDesc,
      puzzleItemToBeUsedWith, puzzleItemProduced, puzzleItemProducedDescription,
      puzzleItemProducedToBeUsedWith;

  PuzzleItem* specificItem = nullptr;
  if (hasPuzzleItem) {
    std::getline(iss, puzzleSpecificItemName, ';');
    std::getline(iss, itemDescription, ';');
    std::getline(iss, puzzleCompleteDesc, ';');
    std::getline(iss, puzzleIncompleteDesc, ';');
    std::getline(iss, puzzleItemToBeUsedWith, ';');
    std::getline(iss, puzzleItemProduced, ';');
    std::getline(iss, puzzleItemProducedDescription, ';');
    std::getline(iss, puzzleItemProducedToBeUsedWith, ';');
    specificItem = new PuzzleItem(
        puzzleSpecificItemName, itemDescription, puzzleCompleteDesc,
        puzzleIncompleteDesc, puzzleItemToBeUsedWith, puzzleItemProduced,
        puzzleItemProducedDescription, puzzleItemProducedToBeUsedWith);
    specificItem->setItemProduced(puzzleItemProduced);
  }

  iss >> hasRiddle;
  iss.ignore();  // skip the semicolon or newline after the flag

  Riddle* newRiddle = nullptr;
  if (hasRiddle) {
    std::getline(iss, riddleInfo, ';');
    std::getline(iss, riddleAnswer, ';');
    newRiddle = new Riddle(riddleInfo, riddleAnswer);
  }

  Item* reward =
      new Item(rewardItemName, rewardItemDescription, rewardItemToBeUsedWith,
               rewardItemProduced, rewardItemProducedDescription,
               rewardItemProducedtoBeUsedWith);
  Puzzle* roomPuzzle =
      new Puzzle(reward, puzzleInformation, specificItem, newRiddle);

  PuzzleRoom* room =
      new PuzzleRoom(roomNumber, roomName, roomDescription, roomPuzzle);
  if (hasPuzzleItem) {
    Interactable inter =
        Interactable(puzzleItemToBeUsedWith, puzzleIncompleteDesc);
    inter.itemToBeUsedWith = puzzleSpecificItemName;
    room->AddInteractable(inter);
  }
  return room;
}

/**
 * @brief Create a trap room from a given input stream.
 *
 * @param iss The input stream containing the trap room data.
 * @return A pointer to the newly created trap room.
 */
TrapRoom* IOManager::createTrapRoom(std::istringstream& iss) {
  unsigned roomNumber;
  std::string roomName, roomDescription, riddleInfo, riddleAnswer,
      trapDeathMessage, roomNumberStr;

  std::getline(iss, roomNumberStr, ';');
  roomNumber = std::stoi(roomNumberStr);
  std::getline(iss, roomName, ';');
  std::getline(iss, roomDescription, ';');
  std::getline(iss, riddleInfo, ';');
  std::getline(iss, riddleAnswer, ';');
  std::getline(iss, trapDeathMessage, ';');

  Riddle trapRiddle(riddleInfo, riddleAnswer);
  Trap roomTrap(trapRiddle, trapDeathMessage);

  return new TrapRoom(roomNumber, roomName, roomTrap, roomDescription);
}

/**
 * @brief Load connections between rooms in the map from a file.
 *
 * @param map A pointer to the game map.
 * @param rooms A pointer to the vector of loaded rooms.
 */
void IOManager::loadConnections(Map* map, std::vector<Room*>* rooms) {
  std::ifstream connectionFile(connectionsFileLocation);
  std::string line;

  while (std::getline(connectionFile, line)) {
    std::istringstream iss(line);
    std::string srcRoomNumberStr, destRoomNumberStr, direction, gateIndicator,
        itemName, itemDescription, itemProduced, itemToBeUsedWith,
        itemProducedDescription, itemProducedToBeUsedWith;

    std::getline(iss, srcRoomNumberStr, ';');
    std::getline(iss, direction, ';');
    std::getline(iss, destRoomNumberStr, ';');
    std::getline(iss, gateIndicator, ';');

    unsigned srcRoomNumber = std::stoi(srcRoomNumberStr) - 1;
    unsigned destRoomNumber = std::stoi(destRoomNumberStr) - 1;

    Room* srcRoom = rooms->at(srcRoomNumber);
    Room* destRoom = rooms->at(destRoomNumber);

    if (direction == "North")
      srcRoom->setNorthRoom(destRoom);
    else if (direction == "South")
      srcRoom->setSouthRoom(destRoom);
    else if (direction == "East")
      srcRoom->setEastRoom(destRoom);
    else if (direction == "West")
      srcRoom->setWestRoom(destRoom);

    if (gateIndicator == "Gate") {
      std::getline(iss, itemName, ';');
      std::getline(iss, itemDescription, ';');
      std::getline(iss, itemProduced, ';');
      std::getline(iss, itemToBeUsedWith, ';');
      std::getline(iss, itemProducedDescription, ';');
      std::getline(iss, itemProducedToBeUsedWith, ';');
      Gate* newGate = new Gate();
      KeyItem* gateKey =
          new KeyItem(itemName, itemDescription, itemProduced, itemToBeUsedWith,
                      itemProducedDescription, itemProducedToBeUsedWith);
      newGate->name = gateKey->itemToBeUsedWith;
      newGate->itemToBeUsedWith = gateKey->getItemName();
      newGate->setKey(gateKey);

      if (direction == "North")
        srcRoom->setNorthGate(newGate);
      else if (direction == "South")
        srcRoom->setSouthGate(newGate);
      else if (direction == "East")
        srcRoom->setEastGate(newGate);
      else if (direction == "West")
        srcRoom->setWestGate(newGate);
    }
  }
}

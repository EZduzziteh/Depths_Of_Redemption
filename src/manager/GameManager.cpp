/*
 * GameManager.cpp
 *
 *  Created on: Oct. 12, 2023
 *      Author: jp
 */

#include "GameManager.h"

#include <iostream>
#include <limits>
#include <string>

#include "CommandManager.h"
#include "IOManager.h"
#include "Inventory.h"
#include "ItemRoom.h"
#include "KeyPuzzle.h"
#include "Map.h"
#include "MovementManager.h"
#include "NPCRoom.h"
#include "Player.h"
#include "PuzzleRoom.h"
#include "Room.h"
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief Start the game and initialize all components.
 *
 * This function sets up the game environment, displays the game's story,
 * and starts the main game loop, capturing and processing player commands.
 */
void start() {
  IOManager iOManager;
  Map *map = iOManager.generateMapFromFile();  // Load map for the game

  std::cout << "Depths of Redemption" << std::endl << std::endl;
  std::cout
      << "A text-based fantasy adventure By Jacques Pointer and Sasha Greene."
      << std::endl
      << std::endl;

  std::cout << "Legend tells of an ancient tome, the *Tome of Redemption*, a "
               "powerful book filled with ancient"
            << " spells and magic, which is according to legend, in the "
               "possession of a great undead "
            << "spirit known as Awallach, The Traitor Knight." << std::endl
            << "He has been sealed away in a chamber deep beneath the surface "
               "but there has been worry recently, about him being able to "
               "escape and wreak havoc on the realms!"
            << std::endl;
  std::cout << "You have taken it upon yourself, to be the one who slays this "
               "evil spirit and bring peace of mind and grant safety to the "
               "people of the land while also redeeming yourself of a great "
               "sin in the process"
            << std::endl
            << std::endl
            << "In order to search for this tome, you have entered the tomb of "
               "Awallach."
            << std::endl;
  std::cout << std::endl;
  std::cout << "This adventure starts with you.... what is your name?"
            << std::endl
            << std::endl;
  string playerName = getPlayerName();

  Player *player = new Player{playerName};
  Inventory *playerInventory = new Inventory();
  player->setCharacterInventory(playerInventory);

  player->setCurrentRoom(map->getStartingRoom());
  CommandManager *cMan = new CommandManager();
  cMan->player = player;

  cin.ignore(std::numeric_limits<std::streamsize>::max(),
             '\n');  // Clears buffer after getting the name

  while (true) {
    displayStatus(player);
    cMan->GetCommand();
  }

  delete player;
  delete playerInventory;
  delete map;
  delete cMan;
}

/**
 * @brief Prompt the player for their character's name.
 *
 * This function requests the user to input their character's name and returns
 * it.
 *
 * @return The player's entered name as a string.
 */
string getPlayerName() {
  string playerName;

  cout << "Enter your characters name: ";
  cin >> playerName;
  return playerName;
}

/**
 * @brief Display the current status of the player.
 *
 * This function outputs the player's current name, room location,
 * and available movement options to the console.
 *
 * @param player A pointer to the player object to display information for.
 */
void displayStatus(const Player *player) {
  cout << "\nStatus\n";
  cout << "Name: " << player->getCharacterName() << "\n";
  cout << "Current Room: " << player->getCurrentRoom()->getRoomName()
       << std::endl;
  cout << MovementManager::displayAvailableRooms(*player);
  cout << "\n";
}

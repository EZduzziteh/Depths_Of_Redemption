/*
 * CommandManagerTest.cpp
 *
 *  Created on: Oct. 29, 2023
 *      Author: jp  sg
 */

/*
 * CommandManagerTest.cpp
 *
 *  Created on: Oct. 15, 2023
 *      Author: sg
 */
#include "CommandManager.h"
#include "Interactable.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemRoom.h"
#include "KeyPuzzle.h"
#include "Map.h"
#include "MovementManager.h"
#include "Player.h"
#include "PuzzleRoom.h"
#include "Room.h"
#include "gtest/gtest.h"

class CommandManagerTest : public ::testing::Test {
 protected:
  Player* player;
  Inventory* playerInventory;
  ItemRoom* centerRoom;
  CommandManager* cMan;

  // cppcheck-suppress unusedFunction
  virtual void SetUp() {
    centerRoom = new ItemRoom("Center Room");
    Map gameMap;
    gameMap.setStartingRoom(centerRoom);

    cMan = new CommandManager();
    player = new Player("Fred", nullptr, centerRoom);
    playerInventory = new Inventory();
    player->setCharacterInventory(playerInventory);
    cMan->player = player;
  }

  // cppcheck-suppress unusedFunction
  virtual void TearDown() {
    delete player;
    delete centerRoom;
    delete playerInventory;
    delete cMan;
  }
};

TEST_F(CommandManagerTest, TestStringToCommand) {
  EXPECT_EQ(cMan->StringToCommand("move"), CommandManager::move);
  EXPECT_EQ(cMan->StringToCommand("use"), CommandManager::use);
  EXPECT_EQ(cMan->StringToCommand("help"), CommandManager::help);
  EXPECT_EQ(cMan->StringToCommand("quit"), CommandManager::quit);
  EXPECT_EQ(cMan->StringToCommand("unknown_command"), CommandManager::unknown);
}

TEST_F(CommandManagerTest, TestPickupItemFromRoom) {
  KeyItem* key = new KeyItem("key", "A shiny key", "e", "e", "e", "e");
  centerRoom->setRoomItem(key);
  cMan->ExecuteCommand(CommandManager::pickup, "key");
  EXPECT_EQ(player->getCharacterInventory()->GetItems()->at(0)->getItemName(),
            "key");
}

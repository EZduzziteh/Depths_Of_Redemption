#include <iostream>

#include "Map.h"
#include "MovementManager.h"
#include "Player.h"
#include "Room.h"
#include "gtest/gtest.h"

class MovementManagerTest : public ::testing::Test {
 protected:
  Player *player;
  Room *centerRoom;
  Room *northRoom;
  Room *southRoom;
  Room *eastRoom;
  Room *westRoom;

  // cppcheck-suppress unusedFunction
  void SetUp() {
    centerRoom = new Room(0, "Center Room");
    northRoom = new Room(1, "North Room");
    southRoom = new Room(2, "South Room");
    eastRoom = new Room(3, "East Room");
    westRoom = new Room(4, "West Room");

    Map gameMap;
    gameMap.setStartingRoom(centerRoom);
    centerRoom->setNorthRoom(northRoom);
    centerRoom->setSouthRoom(southRoom);
    centerRoom->setEastRoom(eastRoom);
    centerRoom->setWestRoom(westRoom);

    player = new Player("John", nullptr, centerRoom);
  }

  // cppcheck-suppress unusedFunction
  void TearDown() {
    delete player;
    delete centerRoom;
    delete northRoom;
    delete southRoom;
    delete eastRoom;
    delete westRoom;
  }
};

TEST_F(MovementManagerTest, MoveNorthAndBack) {
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_EQ(player->getCurrentRoom(), northRoom);

  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "south"));
  EXPECT_EQ(player->getCurrentRoom(), centerRoom);
}

TEST_F(MovementManagerTest, MoveSouthAndBack) {
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "south"));
  EXPECT_EQ(player->getCurrentRoom(), southRoom);

  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_EQ(player->getCurrentRoom(), centerRoom);
}

TEST_F(MovementManagerTest, InvalidMove) {
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "Northwest"));
}

TEST_F(MovementManagerTest, MoveToUnconnectedRoom) {
  northRoom->setNorthRoom(nullptr);  // Ensuring there's no room connected to
                                     // the north of the northRoom

  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_EQ(player->getCurrentRoom(), northRoom);

  // Attempt to move further north should fail
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "north"));
}

TEST_F(MovementManagerTest, AddRoomNorth) {
  Room *extraNorth = new Room("Extra North Room");
  Map gameMap;
  gameMap.addRoomNorthOf(northRoom, extraNorth);
  EXPECT_EQ(northRoom->getNorthRoom(), extraNorth);
  EXPECT_EQ(extraNorth->getSouthRoom(), northRoom);
  delete extraNorth;
}

TEST_F(MovementManagerTest, AddRoomSouth) {
  Room *extraSouth = new Room("Extra South Room");
  Map gameMap;
  gameMap.addRoomSouthOf(southRoom, extraSouth);
  EXPECT_EQ(southRoom->getSouthRoom(), extraSouth);
  EXPECT_EQ(extraSouth->getNorthRoom(), southRoom);
  delete extraSouth;
}

TEST_F(MovementManagerTest, AddRoomEast) {
  Room *extraEast = new Room("Extra East Room");
  Map gameMap;
  gameMap.addRoomEastOf(eastRoom, extraEast);
  EXPECT_EQ(eastRoom->getEastRoom(), extraEast);
  EXPECT_EQ(extraEast->getWestRoom(), eastRoom);
  delete extraEast;
}

TEST_F(MovementManagerTest, AddRoomWest) {
  Room *extraWest = new Room("Extra West Room");
  Map gameMap;
  gameMap.addRoomWestOf(westRoom, extraWest);
  EXPECT_EQ(westRoom->getWestRoom(), extraWest);
  EXPECT_EQ(extraWest->getEastRoom(), westRoom);
  delete extraWest;
}

TEST_F(MovementManagerTest, MoveInvalidDirection) {
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "Northwest"));
  EXPECT_EQ(player->getCurrentRoom(), centerRoom);
}

TEST_F(MovementManagerTest, NoRoomInDirection) {
  Room *isolatedRoom = new Room("Isolated Room");
  player->setCurrentRoom(isolatedRoom);
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_EQ(player->getCurrentRoom(), isolatedRoom);
  delete isolatedRoom;
}

TEST_F(MovementManagerTest, MovePlayerToStartingRoom) {
  centerRoom->setFirstRoom(true);  // Marking centerRoom as the starting room
  player->setCurrentRoom(eastRoom);
  MovementManager::movePlayerInDirection(player, "west");
  EXPECT_EQ(player->getCurrentRoom(), centerRoom);
}

TEST_F(MovementManagerTest, MultipleSequentialMoves) {
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "south"));
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "east"));
  EXPECT_EQ(player->getCurrentRoom(), eastRoom);
}

TEST_F(MovementManagerTest, MoveToUnconnectedRoomEast) {
  eastRoom->setEastRoom(nullptr);
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "east"));
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "east"));
}

TEST_F(MovementManagerTest, MoveToUnconnectedRoomWest) {
  westRoom->setWestRoom(nullptr);
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "west"));
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "west"));
}

TEST_F(MovementManagerTest, MoveToSelf) {
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "center"));
}

TEST_F(MovementManagerTest, MoveBeyondMapBounds) {
  player->setCurrentRoom(northRoom);
  EXPECT_FALSE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_EQ(player->getCurrentRoom(), northRoom);
}

TEST_F(MovementManagerTest, PlayerRemainsWhenMovingToNullRoom) {
  Room *temporaryRoom = new Room("Temporary Room");
  player->setCurrentRoom(temporaryRoom);
  EXPECT_FALSE(MovementManager::movePlayerInDirection(
      player, "South"));  // Assuming no South room exists
  EXPECT_EQ(player->getCurrentRoom(), temporaryRoom);
  delete temporaryRoom;
}

TEST_F(MovementManagerTest, ChainMultipleMovements) {
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "north"));
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "south"));
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "east"));
  EXPECT_TRUE(MovementManager::movePlayerInDirection(player, "west"));
  EXPECT_EQ(player->getCurrentRoom(), centerRoom);
}

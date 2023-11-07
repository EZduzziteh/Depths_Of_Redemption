/**
 * @file MovementManager.cpp
 * @brief Implementation of the MovementManager class for moving room to room.
 * @date October 12, 2023
 * @author sg, jp
 */

#include "MovementManager.h"

#include <sstream>

/**
 * @namespace MovementManager
 * @brief Contains methods related to moving the player from room to room.
 */
namespace MovementManager {

/**
 * @brief Displays rooms that are available to move to from the player's current
 * location.
 * @param player The current player instance.
 * @return A string representation of available directions and their status
 * (locked/unlocked).
 */
std::string displayAvailableRooms(const Player &player) {
  Room *currentRoom = player.getCurrentRoom();
  std::stringstream ss;

  ss << "Available directions: ";
  if (currentRoom->getNorthRoom()) {
    ss << "[north";
    if (currentRoom->hasGateInDirection("north") &&
        currentRoom->isGateLockedInDirection("north"))
      ss << " - locked";
    ss << "] ";
  }
  if (currentRoom->getSouthRoom()) {
    ss << "[south";
    if (currentRoom->hasGateInDirection("south") &&
        currentRoom->isGateLockedInDirection("south"))
      ss << " - locked";
    ss << "] ";
  }
  if (currentRoom->getEastRoom()) {
    ss << "[east";
    if (currentRoom->hasGateInDirection("east") &&
        currentRoom->isGateLockedInDirection("east"))
      ss << " - locked";
    ss << "] ";
  }
  if (currentRoom->getWestRoom()) {
    ss << "[west";
    if (currentRoom->hasGateInDirection("west") &&
        currentRoom->isGateLockedInDirection("west"))
      ss << " - locked";
    ss << "] ";
  }
  ss << "\n";
  return ss.str();
}

/**
 * @brief Moves the player in a given direction if possible.
 * @param player Pointer to the current player.
 * @param direction The desired direction to move in.
 * @return True if movement is successful, false otherwise.
 */
bool movePlayerInDirection(Player *player, const std::string &direction) {
  Room *newRoom = moveInDirection(player->getCurrentRoom(), direction);
  if (newRoom) {
    player->setCurrentRoom(newRoom);
    return true;
  }
  return false;
}

/**
 * @brief Returns the next room in a given direction if accessible.
 * @param currentRoom Pointer to the current room.
 * @param direction The desired direction to check.
 * @return Pointer to the next room if accessible, nullptr otherwise.
 */
Room *moveInDirection(Room *currentRoom, const std::string &direction) {
  if (isPathBlockedByLockedGate(currentRoom, direction)) return nullptr;

  if (direction == "north" && canMoveNorth(currentRoom))
    return currentRoom->getNorthRoom();
  if (direction == "south" && canMoveSouth(currentRoom))
    return currentRoom->getSouthRoom();
  if (direction == "east" && canMoveEast(currentRoom))
    return currentRoom->getEastRoom();
  if (direction == "west" && canMoveWest(currentRoom))
    return currentRoom->getWestRoom();
  return nullptr;
}

/**
 * @brief Checks if a path is blocked by a locked gate.
 * @param currentRoom Pointer to the current room.
 * @param direction The direction to check.
 * @return True if the path is blocked, false otherwise.
 */
bool isPathBlockedByLockedGate(Room *currentRoom,
                               const std::string &direction) {
  return currentRoom->hasGateInDirection(direction) &&
         currentRoom->isGateLockedInDirection(direction);
}

/**
 * @brief Checks if the player can move north from the current room.
 * @param room Pointer to the current room.
 * @return True if the player can move north, false otherwise.
 */
bool canMoveNorth(Room *room) {
  return room->getNorthRoom() != nullptr &&
         !isPathBlockedByLockedGate(room, "north");
}

/**
 * @brief Checks if the player can move south from the current room.
 * @param room Pointer to the current room.
 * @return True if the player can move south, false otherwise.
 */
bool canMoveSouth(Room *room) {
  return room->getSouthRoom() != nullptr &&
         !isPathBlockedByLockedGate(room, "south");
}

/**
 * @brief Checks if the player can move east from the current room.
 * @param room Pointer to the current room.
 * @return True if the player can move east, false otherwise.
 */
bool canMoveEast(Room *room) {
  return room->getEastRoom() != nullptr &&
         !isPathBlockedByLockedGate(room, "east");
}

/**
 * @brief Checks if the player can move west from the current room.
 * @param room Pointer to the current room.
 * @return True if the player can move west, false otherwise.
 */
bool canMoveWest(Room *room) {
  return room->getWestRoom() != nullptr &&
         !isPathBlockedByLockedGate(room, "west");
}

}  // namespace MovementManager

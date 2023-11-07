#ifndef SRC_MANAGER_MOVEMENTMANAGER_H_
#define SRC_MANAGER_MOVEMENTMANAGER_H_

#include <string>

#include "Player.h"
#include "Room.h"

namespace MovementManager {

// Returns a formatted string of available room directions for the player
std::string displayAvailableRooms(const Player &player);

bool isPathBlockedByLockedGate(Room *currentRoom, const std::string &direction);

// Moves the player in the specified direction, returns true if successful
bool movePlayerInDirection(Player *player, const std::string &direction);

Room *moveInDirection(Room *currentRoom, const std::string &direction);
bool hasLockedGate(Room *currentRoom, const std::string &direction);

// Utility methods to check possibility of movement in a particular direction
bool canMoveNorth(Room *room);
bool canMoveSouth(Room *room);
bool canMoveEast(Room *room);
bool canMoveWest(Room *room);
}  // namespace MovementManager

#endif /* SRC_MANAGER_MOVEMENTMANAGER_H_ */

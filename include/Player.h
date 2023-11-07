#ifndef SRC_ENTITY_PLAYER_H_
#define SRC_ENTITY_PLAYER_H_

#include <string>

#include "Character.h"
#include "Room.h"

class Player : public Character {
 private:
  Room *currentRoom;
  int playerHealth;

 public:
  Player(string playerName);

  // Parameterized constructor
  Player(const string &playerName, Inventory *playerInventory, Room *startRoom,
         int startHealth = 100);

  // Getters and setters
  Room *getCurrentRoom() const;
  void setCurrentRoom(Room *room);
  int getPlayerHealth() const;
  void setPlayerHealth(int h);
};

#endif /* SRC_ENTITY_PLAYER_H_ */

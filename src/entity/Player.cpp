#include "Player.h"

// Default constructor
Player::Player(string playerName)
    : Character{nullptr, playerName}, currentRoom(nullptr), playerHealth(100) {}

// Parameterized constructor
Player::Player(const string &playerName, Inventory *playerInventory,
               Room *startRoom, int startHealth)
    : Character(playerInventory, playerName),
      currentRoom(startRoom),
      playerHealth(startHealth) {}

Room *Player::getCurrentRoom() const { return currentRoom; }

void Player::setCurrentRoom(Room *room) { currentRoom = room; }

int Player::getPlayerHealth() const { return playerHealth; }

void Player::setPlayerHealth(int h) { playerHealth = h; }

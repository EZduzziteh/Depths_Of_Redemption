#include "ItemRoom.h"

// Default constructor
ItemRoom::ItemRoom() : Room(), roomItem(nullptr) {}

// Constructor with roomName from Room
ItemRoom::ItemRoom(std::string roomName) : Room(roomName), roomItem(nullptr) {}

// Constructor with KeyItem
ItemRoom::ItemRoom(KeyItem *item) : Room(), roomItem(item) {}

// Constructor with all parameters from Room and KeyItem
ItemRoom::ItemRoom(unsigned roomNumber, std::string roomName,
                   std::string roomDescription, bool firstRoom, bool lastRoom,
                   Room *northRoom, Room *eastRoom, Room *southRoom,
                   Room *westRoom, Gate *northGate, Gate *eastGate,
                   Gate *southGate, Gate *westGate, KeyItem *item)
    : Room(roomNumber, roomName, roomDescription, firstRoom, lastRoom,
           northRoom, eastRoom, southRoom, westRoom, northGate, eastGate,
           southGate, westGate),
      roomItem(item) {}

// Destructor
ItemRoom::~ItemRoom() {
  delete roomItem;  // Ensure we free the memory for the KeyItem when the
                    // ItemRoom is destroyed
}

// Getter for roomItem
KeyItem *ItemRoom::getRoomItem() const { return roomItem; }

// Setter for roomItem
void ItemRoom::setRoomItem(KeyItem *item) {
  if (roomItem) {
    delete roomItem;  // Remove the previous item before setting a new one to
                      // prevent memory leaks
  }
  roomItem = item;
}

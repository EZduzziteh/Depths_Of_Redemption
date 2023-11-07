#ifndef ITEMROOM_H
#define ITEMROOM_H

#include <string>

#include "KeyItem.h"
#include "Room.h"

class ItemRoom : public Room {
 private:
  KeyItem *roomItem;  // Changed from Inventory to KeyItem*

 public:
  // Default constructor
  ItemRoom();

  // Constructor with roomName from Room
  ItemRoom(std::string roomName);

  // Constructor with KeyItem
  ItemRoom(KeyItem *item);

  // Constructor with all parameters from Room and KeyItem
  ItemRoom(unsigned roomNumber, std::string roomName,
           std::string roomDescription, bool firstRoom = false,
           bool lastRoom = false, Room *northRoom = nullptr,
           Room *eastRoom = nullptr, Room *southRoom = nullptr,
           Room *westRoom = nullptr, Gate *northGate = nullptr,
           Gate *eastGate = nullptr, Gate *southGate = nullptr,
           Gate *westGate = nullptr, KeyItem *item = nullptr);

  // Destructor
  virtual ~ItemRoom();

  // Getter for roomItem
  KeyItem *getRoomItem() const;

  // Setter for roomItem
  void setRoomItem(KeyItem *item);
};

#endif  // ITEMROOM_H

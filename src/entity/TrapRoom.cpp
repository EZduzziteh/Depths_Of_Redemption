#include "TrapRoom.h"

// Default constructor
TrapRoom::TrapRoom() : Room(), roomTrap(), isTrapActive(true) {}

// Constructor with just a room name
TrapRoom::TrapRoom(const std::string &roomName)
    : Room(roomName), roomTrap(), isTrapActive(true) {}

// Fully parameterized constructor
TrapRoom::TrapRoom(unsigned roomNumber, const std::string &roomName,
                   const Trap &trap, const std::string &roomDescription,
                   bool firstRoom, bool lastRoom, Room *northRoom,
                   Room *eastRoom, Room *southRoom, Room *westRoom,
                   Gate *northGate, Gate *eastGate, Gate *southGate,
                   Gate *westGate)
    : Room(roomNumber, roomName, roomDescription, firstRoom, lastRoom,
           northRoom, eastRoom, southRoom, westRoom, northGate, eastGate,
           southGate, westGate),
      roomTrap(trap),
      isTrapActive(true) {}

// Getter for the trap
const Trap &TrapRoom::getRoomTrap() const { return roomTrap; }

// Getter for isTrapActive
bool TrapRoom::trapIsActive() const { return isTrapActive; }

// Setter for isTrapActive
void TrapRoom::setTrapActive(bool isActive) { isTrapActive = isActive; }

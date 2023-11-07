#ifndef SRC_ENTITY_TRAPROOM_H_
#define SRC_ENTITY_TRAPROOM_H_

#include <string>

#include "Room.h"
#include "Trap.h"

class TrapRoom : public Room {
 private:
  Trap roomTrap;
  bool isTrapActive;

 public:
  // Default constructor
  TrapRoom();

  // Constructor with just a room name
  explicit TrapRoom(const std::string &roomName);

  // Fully parameterized constructor
  TrapRoom(unsigned roomNumber, const std::string &roomName, const Trap &trap,
           const std::string &roomDescription = "", bool firstRoom = false,
           bool lastRoom = false, Room *northRoom = nullptr,
           Room *eastRoom = nullptr, Room *southRoom = nullptr,
           Room *westRoom = nullptr, Gate *northGate = nullptr,
           Gate *eastGate = nullptr, Gate *southGate = nullptr,
           Gate *westGate = nullptr);

  // Getter for the trap
  const Trap &getRoomTrap() const;

  // Getter for isTrapActive
  bool trapIsActive() const;

  // Setter for isTrapActive
  void setTrapActive(bool isActive);
};

#endif /* SRC_ENTITY_TRAPROOM_H_ */

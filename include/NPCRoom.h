#ifndef NPCROOM_H
#define NPCROOM_H

#include <string>

#include "NPC.h"
#include "Room.h"

class NPCRoom : public Room {
 private:
  NPC *residentNPC;  // The NPC residing in this room.

 public:
  // Default constructor
  NPCRoom();

  // Constructor with only roomName and NPC
  NPCRoom(std::string name, NPC *npc);

  // Parameterized constructor
  NPCRoom(unsigned number, std::string name, NPC *npc,
          std::string description = "", bool firstRoom = false,
          bool lastRoom = false, Room *northRoom = nullptr,
          Room *eastRoom = nullptr, Room *southRoom = nullptr,
          Room *westRoom = nullptr, Gate *northGate = nullptr,
          Gate *eastGate = nullptr, Gate *southGate = nullptr,
          Gate *westGate = nullptr);

  // Destructor
  ~NPCRoom();

  // Getter for the NPC
  NPC *getResidentNPC() const;

  // Setter for the NPC
  void setResidentNPC(NPC *npc);
};

#endif  // NPCROOM_H

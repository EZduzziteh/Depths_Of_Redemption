#include "NPCRoom.h"

// Default constructor
NPCRoom::NPCRoom() : Room(), residentNPC(nullptr) {}

// Constructor with only roomName and NPC
NPCRoom::NPCRoom(std::string name, NPC *npc) : Room(name), residentNPC(npc) {}

// Parameterized constructor
NPCRoom::NPCRoom(unsigned number, std::string name, NPC *npc,
                 std::string description, bool first, bool last, Room *north,
                 Room *east, Room *south, Room *west, Gate *northGate,
                 Gate *eastGate, Gate *southGate, Gate *westGate)
    : Room(number, name, description, first, last, north, east, south, west,
           northGate, eastGate, southGate, westGate),
      residentNPC(npc) {}

// Destructor
NPCRoom::~NPCRoom() {
  if (residentNPC) {
    delete residentNPC;
    residentNPC = nullptr;
  }
}

// Getter for the NPC
NPC *NPCRoom::getResidentNPC() const { return residentNPC; }

// Setter for the NPC
void NPCRoom::setResidentNPC(NPC *npc) {
  if (residentNPC) {
    delete residentNPC;
  }
  residentNPC = npc;
}

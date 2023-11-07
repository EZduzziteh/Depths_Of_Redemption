#include "Room.h"

// Constructors
Room::Room()
    : roomNumber(0),
      roomName(""),
      roomDescription(""),
      northRoom(nullptr),
      southRoom(nullptr),
      eastRoom(nullptr),
      westRoom(nullptr),
      firstRoom(false),
      lastRoom(false),
      northGate(nullptr),
      eastGate(nullptr),
      southGate(nullptr),
      westGate(nullptr) {
  interactables = new std::vector<Interactable>();
}

// Constructor with roomName only
Room::Room(string name)
    : roomNumber(0),
      roomName(name),
      roomDescription(""),
      northRoom(nullptr),
      southRoom(nullptr),
      eastRoom(nullptr),
      westRoom(nullptr),
      firstRoom(false),
      lastRoom(false),
      northGate(nullptr),
      eastGate(nullptr),
      southGate(nullptr),
      westGate(nullptr) {
  interactables = new std::vector<Interactable>();
}

// Parameterized constructor
Room::Room(unsigned number, string name, string description, bool first,
           bool last, Room *north, Room *east, Room *south, Room *west,
           Gate *nGate, Gate *eGate, Gate *sGate, Gate *wGate)
    : roomNumber(number),
      roomName(name),
      roomDescription(description),
      northRoom(north),
      southRoom(south),
      eastRoom(east),
      westRoom(west),
      firstRoom(first),
      lastRoom(last),
      northGate(nGate),
      eastGate(eGate),
      southGate(sGate),
      westGate(wGate) {
  interactables = new std::vector<Interactable>();
}

// Destructor
Room::~Room() {
  delete interactables;
  delete northGate;
  delete eastGate;
  delete southGate;
  delete westGate;
}

// Getters
unsigned Room::getRoomNumber() const { return roomNumber; }
string Room::getRoomName() const { return roomName; }
string Room::getRoomDescription() const { return roomDescription; }
Room *Room::getNorthRoom() const { return northRoom; }
Room *Room::getSouthRoom() const { return southRoom; }
Room *Room::getEastRoom() const { return eastRoom; }
Room *Room::getWestRoom() const { return westRoom; }
bool Room::isFirstRoom() const { return firstRoom; }
bool Room::isLastRoom() const { return lastRoom; }

// Setters
void Room::setRoomDescription(const string &description) {
  roomDescription = description;
}
void Room::setNorthRoom(Room *room) {
  if (northRoom != room) {  // Avoid infinite loop
    northRoom = room;
    if (room) room->setSouthRoom(this);  // Set the reverse relationship
  }
}

void Room::setSouthRoom(Room *room) {
  if (southRoom != room) {  // Avoid infinite loop
    southRoom = room;
    if (room) room->setNorthRoom(this);  // Set the reverse relationship
  }
}

void Room::setEastRoom(Room *room) {
  if (eastRoom != room) {  // Avoid infinite loop
    eastRoom = room;
    if (room) room->setWestRoom(this);  // Set the reverse relationship
  }
}

void Room::setWestRoom(Room *room) {
  if (westRoom != room) {  // Avoid infinite loop
    westRoom = room;
    if (room) room->setEastRoom(this);  // Set the reverse relationship
  }
}
void Room::setFirstRoom(bool is_first) { firstRoom = is_first; }
void Room::setLastRoom(bool is_last) { lastRoom = is_last; }

void Room::AddInteractable(const Interactable &interactable) {
  interactables->push_back(interactable);
}

// Gate-related methods

bool Room::hasGateInDirection(const string &direction) const {
  if (direction == "north" && northGate) return true;
  if (direction == "east" && eastGate) return true;
  if (direction == "south" && southGate) return true;
  if (direction == "west" && westGate) return true;
  return false;
}

bool Room::isGateLockedInDirection(const string &direction) const {
  if (direction == "north" && northGate && northGate->isLocked()) return true;
  if (direction == "east" && eastGate && eastGate->isLocked()) return true;
  if (direction == "south" && southGate && southGate->isLocked()) return true;
  if (direction == "west" && westGate && westGate->isLocked()) return true;
  return false;
}

Gate *Room::getGateInDirection(const string &direction) {
  if (direction == "north") return northGate;
  if (direction == "east") return eastGate;
  if (direction == "south") return southGate;
  if (direction == "west") return westGate;
  return nullptr;
}

void Room::setNorthGate(Gate *gate) {
  northGate = gate;
  AddInteractable(Gate());
}
void Room::setEastGate(Gate *gate) { eastGate = gate; }
void Room::setSouthGate(Gate *gate) { southGate = gate; }
void Room::setWestGate(Gate *gate) { westGate = gate; }

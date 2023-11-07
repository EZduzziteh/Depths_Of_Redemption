#ifndef SRC_ENTITY_ROOM_H_
#define SRC_ENTITY_ROOM_H_

#include <string>
#include <vector>

#include "Gate.h"
#include "Interactable.h"
using std::string;
using std::vector;

class Room {
 private:
  unsigned roomNumber;
  string roomName;
  Room *northRoom;
  Room *southRoom;
  Room *eastRoom;
  Room *westRoom;
  bool firstRoom;
  bool lastRoom;

 public:
  Gate *northGate = nullptr;
  Gate *eastGate = nullptr;
  Gate *southGate = nullptr;
  Gate *westGate = nullptr;

 protected:
  string roomDescription;

 public:
  Room();
  Room(string roomName);
  Room(unsigned roomNumber, string roomName, string roomDescription = "",
       bool firstRoom = false, bool lastRoom = false, Room *northRoom = nullptr,
       Room *eastRoom = nullptr, Room *southRoom = nullptr,
       Room *westRoom = nullptr, Gate *northGate = nullptr,
       Gate *eastGate = nullptr, Gate *southGate = nullptr,
       Gate *westGate = nullptr);

  virtual ~Room();  // Already provided

  // Getters
  unsigned getRoomNumber() const;
  string getRoomName() const;

  vector<Interactable> *interactables;
  void AddInteractable(const Interactable &interactable);  // Add interactable

  // Getters
  string getRoomDescription() const;
  Room *getNorthRoom() const;
  Room *getSouthRoom() const;
  Room *getEastRoom() const;
  Room *getWestRoom() const;
  bool isFirstRoom() const;
  bool isLastRoom() const;

  // Setters
  void setRoomDescription(const string &description);
  void setNorthRoom(Room *room);
  void setSouthRoom(Room *room);
  void setEastRoom(Room *room);
  void setWestRoom(Room *room);
  void setFirstRoom(bool is_first);
  void setLastRoom(bool is_last);

  // Gate-related methods
  bool hasGateInDirection(const string &direction) const;
  bool isGateLockedInDirection(const string &direction) const;
  Gate *getGateInDirection(const string &direction);
  void setNorthGate(Gate *gate);
  void setEastGate(Gate *gate);
  void setSouthGate(Gate *gate);
  void setWestGate(Gate *gate);
};

#endif /* SRC_ENTITY_ROOM_H_ */

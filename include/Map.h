#ifndef SRC_ENTITY_MAP_H_
#define SRC_ENTITY_MAP_H_

#include "Room.h"

class Map {
 private:
  Room *startingRoom;  // This can be any room, but we'll use it as a reference
                       // point
  Room *lastRoom;

 public:
  Map();
  Map(Room *startingRoom);
  ~Map();

  void addRoomNorthOf(Room *baseRoom, Room *newRoom);
  void addRoomSouthOf(Room *baseRoom, Room *newRoom);
  void addRoomEastOf(Room *baseRoom, Room *newRoom);
  void addRoomWestOf(Room *baseRoom, Room *newRoom);

  void setStartingRoom(Room *startingRoom);
  void setLastRoom(Room *lastRoom);
  Room *getLastRoom() const;
  Room *getStartingRoom() const;
};

#endif /* SRC_ENTITY_MAP_H_ */

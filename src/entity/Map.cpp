#include "Map.h"
Map::Map() {
  startingRoom = nullptr;
  lastRoom = nullptr;
}

Map::Map(Room *startingRoom) : startingRoom{startingRoom} {
  lastRoom = nullptr;
}

Map::~Map() {}

void Map::addRoomNorthOf(Room *baseRoom, Room *newRoom) {
  baseRoom->setNorthRoom(newRoom);
  newRoom->setSouthRoom(baseRoom);
}

void Map::addRoomSouthOf(Room *baseRoom, Room *newRoom) {
  baseRoom->setSouthRoom(newRoom);
  newRoom->setNorthRoom(baseRoom);
}

void Map::addRoomEastOf(Room *baseRoom, Room *newRoom) {
  baseRoom->setEastRoom(newRoom);
  newRoom->setWestRoom(baseRoom);
}

void Map::addRoomWestOf(Room *baseRoom, Room *newRoom) {
  baseRoom->setWestRoom(newRoom);
  newRoom->setEastRoom(baseRoom);
}

void Map::setStartingRoom(Room *startingRoom) {
  this->startingRoom = startingRoom;
}

void Map::setLastRoom(Room *lastRoom) { this->lastRoom = lastRoom; }

Room *Map::getStartingRoom() const { return startingRoom; }

Room *Map::getLastRoom() const { return lastRoom; }

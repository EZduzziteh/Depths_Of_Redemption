#include "PuzzleRoom.h"

// Default constructor
PuzzleRoom::PuzzleRoom() : Room(), roomPuzzle(nullptr) {}

// Constructor with just a room name
PuzzleRoom::PuzzleRoom(std::string roomName)
    : Room(roomName), roomPuzzle(nullptr) {}

// Constructor with just a puzzle
PuzzleRoom::PuzzleRoom(Puzzle *puzzle) : Room(), roomPuzzle(puzzle) {}

// Constructor with room name and puzzle
PuzzleRoom::PuzzleRoom(std::string roomName, Puzzle *puzzle)
    : Room(roomName), roomPuzzle(puzzle) {}

// Constructor for roomNumber, roomName, roomDescription, and puzzle
PuzzleRoom::PuzzleRoom(unsigned roomNumber, std::string roomName,
                       std::string roomDescription, Puzzle *puzzle)
    : Room(roomNumber, roomName, roomDescription), roomPuzzle(puzzle) {}

// Fully parameterized constructor
PuzzleRoom::PuzzleRoom(unsigned roomNumber, std::string roomName,
                       std::string roomDescription, bool firstRoom,
                       bool lastRoom, Room *northRoom, Room *eastRoom,
                       Room *southRoom, Room *westRoom, Gate *northGate,
                       Gate *eastGate, Gate *southGate, Gate *westGate,
                       Puzzle *puzzle)
    : Room(roomNumber, roomName, roomDescription, firstRoom, lastRoom,
           northRoom, eastRoom, southRoom, westRoom, northGate, eastGate,
           southGate, westGate),
      roomPuzzle(puzzle) {}

// Destructor
PuzzleRoom::~PuzzleRoom() {
  if (roomPuzzle) {
    delete roomPuzzle;
  }
}

// Getter for roomPuzzle
Puzzle *PuzzleRoom::getRoomPuzzle() const { return roomPuzzle; }

// Setter for roomPuzzle
void PuzzleRoom::setRoomPuzzle(Puzzle *puzzle) {
  if (roomPuzzle) {
    delete roomPuzzle;
  }
  roomPuzzle = puzzle;
}

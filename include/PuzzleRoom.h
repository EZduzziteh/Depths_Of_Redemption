#ifndef PUZZLEROOM_H
#define PUZZLEROOM_H

#include <string>

#include "Puzzle.h"
#include "Room.h"

class PuzzleRoom : public Room {
 private:
  Puzzle *roomPuzzle;

 public:
  // Default constructor
  PuzzleRoom();

  // Constructor with just a room name
  PuzzleRoom(std::string roomName);

  // Constructor with just a puzzle
  PuzzleRoom(Puzzle *puzzle);

  // Constructor with room name and puzzle
  PuzzleRoom(std::string roomName, Puzzle *puzzle);

  // Constructor for roomNumber, roomName, roomDescription, and puzzle
  PuzzleRoom(unsigned roomNumber, std::string roomName,
             std::string roomDescription, Puzzle *puzzle);

  // Fully parameterized constructor
  PuzzleRoom(unsigned roomNumber, std::string roomName,
             std::string roomDescription, bool firstRoom, bool lastRoom,
             Room *northRoom, Room *eastRoom, Room *southRoom, Room *westRoom,
             Gate *northGate, Gate *eastGate, Gate *southGate, Gate *westGate,
             Puzzle *puzzle);

  // Destructor
  virtual ~PuzzleRoom();

  // Getter for roomPuzzle
  Puzzle *getRoomPuzzle() const;

  // Setter for roomPuzzle
  void setRoomPuzzle(Puzzle *puzzle);
};

#endif  // PUZZLEROOM_H

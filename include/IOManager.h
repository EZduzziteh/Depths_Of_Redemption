#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "ItemRoom.h"
#include "Map.h"
#include "NPCRoom.h"
#include "PuzzleRoom.h"
#include "Room.h"
#include "TrapRoom.h"

class IOManager {
 private:
  // Room creation methods based on specific room types
  Room* createBasicRoom(std::istringstream& iss);
  ItemRoom* createItemRoom(std::istringstream& iss);
  NPCRoom* createNPCRoom(std::istringstream& iss);
  PuzzleRoom* createPuzzleRoom(std::istringstream& iss);
  TrapRoom* createTrapRoom(std::istringstream& iss);
  static inline const std::string roomsFileLocation = "assets/files/rooms.txt";
  static inline const std::string connectionsFileLocation =
      "assets/files/connections.txt";

  // Load connections between rooms and set gates
  void loadConnections(Map* map, std::vector<Room*>* rooms);

 public:
  IOManager();

  // Generate the map using data from a file
  Map* generateMapFromFile();
};

#endif  // IOManager_H

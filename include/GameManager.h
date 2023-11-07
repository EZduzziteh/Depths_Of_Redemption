/*
 * GameManager.h
 *
 *  Created on: Oct. 12, 2023
 *      Author: jp
 */

#ifndef SRC_MANAGER_GAMEMANAGER_H_
#define SRC_MANAGER_GAMEMANAGER_H_

#include <string>

#include "Map.h"
#include "Player.h"

using std::string;
void CleanUpPointer();
void start();
string getPlayerName();
Map* generateMap();
void displayStatus(const Player* player);

#endif /* SRC_MANAGER_GAMEMANAGER_H_ */

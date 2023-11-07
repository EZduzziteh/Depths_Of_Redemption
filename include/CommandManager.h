/*
 * CommandManager.h
 *
 *  Created on: Oct. 12, 2023
 *      Author: sg
 */

#ifndef SRC_MANAGER_COMMANDMANAGER_H_
#define SRC_MANAGER_COMMANDMANAGER_H_

#include <string>

#include "MovementManager.h"
#include "Player.h"
#include "Riddle.h"
using std::string;

class CommandManager {
 public:
  enum Command {
    move,
    use,
    examine,
    help,
    pickup,
    unknown,
    talk,
    answer,
    quit,
    inventory,
    unlock,
    give
  };
  Player* player;
  CommandManager();
  virtual ~CommandManager();
  void GetCommand();

  void Help();

  //#TODO split these up into separate classes based on the command type
  //- I didn't want to do this yet as I dont want the file structure to change
  // and break our make file. sg
  void ExecuteCommand(Command cmd);
  void ExecuteCommand(Command cmd, string subject1);
  void ExecuteCommand(Command cmd, string subject1, string subject2);
  void Move();
  void Move(string direction);
  void Use();
  void Use(string subject1);
  void Use(string subject1, std::string subject2);
  void Examine();
  void Examine(string subject1);
  void PickUp();
  void PickUp(string subject1);
  void Talk();
  void Talk(string subject1);
  void Answer();
  void Answer(string subject1);
  void Inventory();
  void Quit();
  void Give();
  void Give(string subject1, string subject2);
  void Unlock();
  void Unlock(string subject1);
  bool TrapRiddleChecker(Riddle riddle, string answer);

  Command StringToCommand(string cmd);

 private:
};

#endif /* SRC_MANAGER_COMMANDMANAGER_H_ */

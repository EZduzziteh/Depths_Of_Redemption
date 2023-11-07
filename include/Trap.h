#ifndef TRAP_H
#define TRAP_H

#include <string>

#include "Riddle.h"

using std::string;

class Trap {
 private:
  Riddle trapRiddle;
  string trapDeathMessage;
  bool trapActivated;

 public:
  Trap();
  Trap(const Riddle &riddle, const string &deathMessage);

  // Getters
  Riddle getTrapRiddle() const;
  string getTrapDeathMessage() const;
  bool isTrapActivated() const;

  // Setters
  void setTrapRiddle(const Riddle &riddle);
  void setTrapDeathMessage(const string &deathMessage);
  void setTrapActivated(bool activated);

  // Interaction method
  bool attemptToSolve(const string &answer);
};

#endif  // TRAP_H

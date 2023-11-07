#include "Trap.h"

Trap::Trap() : trapDeathMessage(""), trapActivated(false) {}

Trap::Trap(const Riddle &riddle, const string &deathMessage)
    : trapRiddle(riddle),
      trapDeathMessage(deathMessage),
      trapActivated(false) {}

// Getters
Riddle Trap::getTrapRiddle() const { return trapRiddle; }

string Trap::getTrapDeathMessage() const { return trapDeathMessage; }

bool Trap::isTrapActivated() const { return trapActivated; }

// Setters
void Trap::setTrapRiddle(const Riddle &riddle) { trapRiddle = riddle; }

void Trap::setTrapDeathMessage(const string &deathMessage) {
  trapDeathMessage = deathMessage;
}

void Trap::setTrapActivated(bool activated) { trapActivated = activated; }

// Interaction method
bool Trap::attemptToSolve(const string &answer) {
  if (trapRiddle.getRiddleAnswer() == answer) {
    trapRiddle.setRiddleSolved(true);
    return true;  // Correct answer
  } else {
    return false;  // Incorrect answer
  }
}

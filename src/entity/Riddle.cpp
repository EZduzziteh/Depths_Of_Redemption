#include "Riddle.h"

Riddle::Riddle() : riddleInfo(""), riddleAnswer(""), riddleSolved(false) {
  // Default constructor
}

Riddle::Riddle(const string &info, const string &answer)
    : riddleInfo(info), riddleAnswer(answer), riddleSolved(false) {
  // Parameterized constructor
}

string Riddle::getRiddleInfo() const { return riddleInfo; }

string Riddle::getRiddleAnswer() const { return riddleAnswer; }

bool Riddle::isRiddleSolved() const { return riddleSolved; }

void Riddle::setRiddleInfo(const string &info) { riddleInfo = info; }

void Riddle::setRiddleAnswer(const string &answer) { riddleAnswer = answer; }

void Riddle::setRiddleSolved(bool solved) { riddleSolved = solved; }

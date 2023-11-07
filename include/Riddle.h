#ifndef RIDDLE_H
#define RIDDLE_H

#include <string>

using std::string;

class Riddle {
 private:
  string riddleInfo;
  string riddleAnswer;
  bool riddleSolved;

 public:
  Riddle();
  Riddle(const string &info, const string &answer);

  // Getters
  string getRiddleInfo() const;
  string getRiddleAnswer() const;
  bool isRiddleSolved() const;

  // Setters
  void setRiddleInfo(const string &info);
  void setRiddleAnswer(const string &answer);
  void setRiddleSolved(bool solved);

  // Other methods if needed
};

#endif  // RIDDLE_H

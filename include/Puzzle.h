#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

#include "Item.h"
#include "PuzzleItem.h"
#include "Riddle.h"

using std::string;

class Puzzle {
 private:
  Riddle* puzzleRiddle;
  Item* rewardItem;
  PuzzleItem* puzzleSpecificItem;
  string puzzleInformation;
  bool puzzleComplete;

 public:
  // Full constructor
  Puzzle(Item* rewardItem, const string& info, PuzzleItem* pItem = nullptr,
         Riddle* puzzleRiddle = nullptr, bool isComplete = false);

  // Destructor
  virtual ~Puzzle();

  // Getters and Setters
  Riddle* getPuzzleRiddle() const;
  Item* getRewardItem() const;
  PuzzleItem* getPuzzleSpecificItem() const;
  string getPuzzleInformation() const;
  bool isPuzzleComplete() const;  // Use 'is' prefix for clarity

  void setPuzzleRiddle(Riddle* riddle);
  void setRewardItem(Item* item);
  void setPuzzleSpecificItem(PuzzleItem* specificItem);
  void setPuzzleInformation(const string& info);
  void CompletePuzzle();
};

#endif  // PUZZLE_H

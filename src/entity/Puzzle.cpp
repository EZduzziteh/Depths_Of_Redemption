// Puzzle.cpp
#include "Puzzle.h"

#include <iostream>

// Full constructor
Puzzle::Puzzle(Item* rItem, const string& info, PuzzleItem* pItem,
               Riddle* riddle, bool isComplete)
    : rewardItem(rItem),
      puzzleInformation(info),
      puzzleSpecificItem(pItem),
      puzzleRiddle(riddle),
      puzzleComplete(isComplete) {}

// Destructor
Puzzle::~Puzzle() {
  delete puzzleRiddle;
  delete rewardItem;
  delete puzzleSpecificItem;
}

// Getters
Riddle* Puzzle::getPuzzleRiddle() const { return puzzleRiddle; }

Item* Puzzle::getRewardItem() const { return rewardItem; }

PuzzleItem* Puzzle::getPuzzleSpecificItem() const { return puzzleSpecificItem; }

string Puzzle::getPuzzleInformation() const { return puzzleInformation; }

// Setters
void Puzzle::setPuzzleRiddle(Riddle* riddle) {
  if (puzzleRiddle) {
    delete puzzleRiddle;  // clean up existing dynamic memory
  }
  puzzleRiddle = riddle;
}

void Puzzle::setRewardItem(Item* item) {
  if (rewardItem) {
    delete rewardItem;  // clean up existing dynamic memory
  }
  rewardItem = item;
}

void Puzzle::setPuzzleSpecificItem(PuzzleItem* specificItem) {
  if (puzzleSpecificItem) {
    delete puzzleSpecificItem;  // clean up existing dynamic memory
  }
  puzzleSpecificItem = specificItem;
}

void Puzzle::setPuzzleInformation(const string& info) {
  puzzleInformation = info;
}

void Puzzle::CompletePuzzle() {
  std::cout << puzzleSpecificItem->getPuzzleCompleteDesc();
}

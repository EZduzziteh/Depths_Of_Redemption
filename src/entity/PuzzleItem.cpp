#include "PuzzleItem.h"

// Default constructor
PuzzleItem::PuzzleItem() : Item() {}

// Parameterized constructor
PuzzleItem::PuzzleItem(const std::string &name, const std::string &description,
                       const std::string &completeDesc,
                       const std::string &incompleteDesc,
                       const std::string &itemToBeUsedWith,
                       const std::string &itemProduced,
                       const std::string &itemProducedDescription,
                       const std::string &itemProducedToBeUsedWith)
    : Item(name, description, itemToBeUsedWith, itemProduced,
           itemProducedDescription, itemProducedToBeUsedWith),
      puzzleCompleteDesc(completeDesc),
      puzzleIncompleteDesc(incompleteDesc) {}

// Destructor
PuzzleItem::~PuzzleItem() {}

// Getter for puzzleCompleteDesc
std::string PuzzleItem::getPuzzleCompleteDesc() const {
  return puzzleCompleteDesc;
}

// Getter for puzzleIncompleteDesc
std::string PuzzleItem::getPuzzleIncompleteDesc() const {
  return puzzleIncompleteDesc;
}

// Setter for puzzleCompleteDesc
void PuzzleItem::setPuzzleCompleteDesc(const std::string &desc) {
  puzzleCompleteDesc = desc;
}

// Setter for puzzleIncompleteDesc
void PuzzleItem::setPuzzleIncompleteDesc(const std::string &desc) {
  puzzleIncompleteDesc = desc;
}

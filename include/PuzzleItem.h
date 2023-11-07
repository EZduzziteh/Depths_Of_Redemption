#ifndef SRC_ENTITY_PUZZLEITEM_H_
#define SRC_ENTITY_PUZZLEITEM_H_

#include <string>

#include "Item.h"
class PuzzleItem : public Item {
 private:
  std::string puzzleCompleteDesc;
  std::string puzzleIncompleteDesc;

 public:
  PuzzleItem();
  PuzzleItem(const std::string &name, const std::string &description,
             const std::string &completeDesc,
             const std::string &incompleteDesc,
             const std::string &itemToBeUsedWith,
             const std::string &itemProduced,
             const std::string &itemProducedDescription,
             const std::string &itemProducedToBeUsedWith);
  virtual ~PuzzleItem();

  std::string getPuzzleCompleteDesc() const;
  std::string getPuzzleIncompleteDesc() const;

  void setPuzzleCompleteDesc(const std::string &desc);
  void setPuzzleIncompleteDesc(const std::string &desc);
};

#endif /* SRC_ENTITY_PUZZLEITEM_H_ */

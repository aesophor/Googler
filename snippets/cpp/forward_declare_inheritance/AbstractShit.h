#ifndef ABSTRACT_H_
#define ABSTRACT_H_

#include <iostream>

class PauseMenu;

class AbstractShit {
 public:
  virtual ~AbstractShit();
  virtual void rant() = 0;

 protected:
  AbstractShit() = default;
  PauseMenu* _pauseMenu;
};

#endif // ABSTRACT_H_

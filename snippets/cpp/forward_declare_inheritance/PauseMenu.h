#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "Stats.h"
#include "HeaderPane.h"

class PauseMenu {
 public:
  PauseMenu() = default;
  virtual ~PauseMenu() = default;

 private:
  Stats* _stats;
  HeaderPane* _h;
};

#endif // PAUSE_MENU_H_

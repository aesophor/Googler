#ifndef HEADER_PANE_H_
#define HEADER_PANE_H_

#include "AbstractShit.h"

class HeaderPane : public AbstractShit {
 public:
  HeaderPane() = default;
  virtual ~HeaderPane() = default;
  virtual void rant() override {}
};

#endif // HEADER_PANE_H_

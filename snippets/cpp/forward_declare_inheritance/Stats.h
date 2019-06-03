#ifndef STATS_H_
#define STATS_H_

#include "AbstractShit.h"

class Stats : public AbstractShit {
 public:
  Stats() = default;
  virtual ~Stats();
  virtual void rant() override {}
};

#endif // STATS_H_

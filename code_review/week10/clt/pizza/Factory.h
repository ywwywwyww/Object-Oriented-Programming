#ifndef FACTORY_H_
#define FACTORY_H_

#include <string>

#include "Pizza.h"

class Factory {
 public:
  Factory() = default;
  static std::string random_id(int n = 16) {
    std::string tmp;
    for (int i = 0; i < n; ++i) {
      int rnd = rand() % 36;
      if (rnd < 26)
        tmp += static_cast<char>(rnd + 'a');
      else
        tmp += static_cast<char>(rnd + '0' - 26);
    }
    return tmp;
  }
  virtual Pizza* making() = 0;
  virtual ~Factory() = default;
};

#endif /* FACTORY_H_ */
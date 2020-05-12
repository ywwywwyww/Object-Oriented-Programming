#ifndef CHEESEPIZZAFACTORY_H_
#define CHEESEPIZZAFACTORY_H_

#include <string>

#include "CheesePizza.h"
#include "Factory.h"

class CheesePizzaFactory : public Factory {
 public:
  virtual Pizza* making() {
    std::string id{random_id()};
    return new CheesePizza{id};
  }
  virtual ~CheesePizzaFactory() = default;
};

#endif /* CHEESEPIZZAFACTORY_H_ */
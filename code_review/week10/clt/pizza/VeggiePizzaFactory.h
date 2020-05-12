#ifndef VEGGIEPIZZAFACTORY_H_
#define VEGGIEPIZZAFACTORY_H_

#include <string>

#include "Factory.h"
#include "VeggiePizza.h"

class VeggiePizzaFactory : public Factory {
 public:
  virtual Pizza* making() {
    std::string id{random_id()};
    return new VeggiePizza{id};
  }
  virtual ~VeggiePizzaFactory() = default;
};

#endif /* VEGGIEPIZZAFACTORY_H_ */
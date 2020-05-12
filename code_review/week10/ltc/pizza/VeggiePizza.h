#ifndef VEGGIEPIZZA_H_
#define VEGGIEPIZZA_H_

#include <iostream>
#include <string>

#include "Pizza.h"
class VeggiePizza : public Pizza {
 public:
  VeggiePizza(std::string id) : Pizza(id) {
    // To see the id of each pizza, note off the next line.
    // std::cout << "Making VeggiePizza " << id << "\n";
  }
  virtual ~VeggiePizza() = default;
};

#endif /* VEGGIEPIZZA_H_ */
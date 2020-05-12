#ifndef CHEESEPIZZA_H_
#define CHEESEPIZZA_H_

#include <iostream>
#include <string>

#include "Pizza.h"
class CheesePizza : public Pizza {
 public:
  CheesePizza(std::string id) : Pizza(id) {
    // To see the id of each pizza, note off the next line.
    // std::cout << "Making CheesePizza " << id << "\n";
  }
  virtual ~CheesePizza() = default;
};

#endif /* CHEESEPIZZA_H_ */
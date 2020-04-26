/**
 * @file pizza.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__PIZZA_H_
#define PROBLEM1__PIZZA_H_

#include <string>
#include <iostream>

class Pizza {
 public:
  Pizza();
  virtual void SellPizza(std::ostream &out = std::cout) = 0;
  const std::string &GetId();
  virtual ~Pizza() = default;
 protected:
  std::string id_;
};

#endif //PROBLEM1__PIZZA_H_

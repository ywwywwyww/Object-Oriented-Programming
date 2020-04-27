/**
 * @file pizza.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__PIZZA_H_
#define PROBLEM1__PIZZA_H_

#include <string>
#include <iostream>

/**
 * Almost the same as example
 */
class Pizza {
 public:
  Pizza();
  virtual void SellPizza(std::ostream &out = std::cout) = 0;
  /**
   * Gets id of the pizza
   * @return Id of the pizza
   */
  const std::string &GetId();
  virtual ~Pizza() = default;
 protected:
  std::string id_; // Id of the pizza
};

#endif //PROBLEM1__PIZZA_H_

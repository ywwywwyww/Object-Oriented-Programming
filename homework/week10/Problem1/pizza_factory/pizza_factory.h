/**
 * @file pizza_factory.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__PIZZA_FACTORY_H_
#define PROBLEM1__PIZZA_FACTORY_H_

#include "../pizza/pizza.h"

/**
 * The same as example
 */
class PizzaFactory {
 public:
  virtual Pizza* CreatePizza() = 0;
  virtual ~PizzaFactory() = default;
};

#endif //PROBLEM1__PIZZA_FACTORY_H_

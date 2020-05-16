/**
 * @file cheese_pizza_factory.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__CHEESE_PIZZA_FACTORY_H_
#define PROBLEM1__CHEESE_PIZZA_FACTORY_H_

#include "pizza_factory.h"

class CheesePizzaFactory : public PizzaFactory {
 public:
  std::shared_ptr<Pizza> CreatePizza() override;
};

#endif //PROBLEM1__CHEESE_PIZZA_FACTORY_H_

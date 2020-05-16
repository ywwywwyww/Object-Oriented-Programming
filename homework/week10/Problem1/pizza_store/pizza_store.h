/**
 * @file pizza_store.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__PIZZA_STORE_H_
#define PROBLEM1__PIZZA_STORE_H_

#include "../pizza/pizza.h"
#include "../pizza_factory/pizza_factory.h"

/**
 * The same as example
 */
class PizzaStore {
 public:
  std::shared_ptr<Pizza> OrderPizza(std::shared_ptr<PizzaFactory> factory);
};

#endif //PROBLEM1__PIZZA_STORE_H_

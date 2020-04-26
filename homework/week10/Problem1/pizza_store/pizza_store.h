/**
 * @file pizza_store.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__PIZZA_STORE_H_
#define PROBLEM1__PIZZA_STORE_H_

#include "../pizza/pizza.h"
#include "../pizza_factory/pizza_factory.h"

class PizzaStore {
 public:
  Pizza* OrderPizza(PizzaFactory *factory);
};

#endif //PROBLEM1__PIZZA_STORE_H_

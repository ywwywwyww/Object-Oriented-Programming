/**
 * @file veggie_pizza_factory.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1__VEGGIE_PIZZA_FACTORY_H_
#define PROBLEM1__VEGGIE_PIZZA_FACTORY_H_

#include "../pizza/pizza.h"
#include "pizza_factory.h"

class VeggiePizzaFactory : public PizzaFactory {
 public:
  Pizza* CreatePizza();
};

#endif //PROBLEM1__VEGGIE_PIZZA_FACTORY_H_

/**
 * @file veggie_pizza_factory.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "veggie_pizza_factory.h"
#include "../pizza/veggie_pizza.h"

std::shared_ptr<Pizza> VeggiePizzaFactory::CreatePizza() {
  std::shared_ptr<Pizza> pizza{new VeggiePizza};
  return pizza;
}
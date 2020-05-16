/**
 * @file cheese_pizza_factory.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "cheese_pizza_factory.h"
#include "../pizza/cheese_pizza.h"

std::shared_ptr<Pizza> CheesePizzaFactory::CreatePizza() {
  std::shared_ptr<Pizza> pizza {new CheesePizza};
  return pizza;
}
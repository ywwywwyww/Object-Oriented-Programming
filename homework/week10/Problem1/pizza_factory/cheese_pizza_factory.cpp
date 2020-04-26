/**
 * @file cheese_pizza_factory.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "cheese_pizza_factory.h"
#include "../pizza/cheese_pizza.h"

Pizza * CheesePizzaFactory::CreatePizza() {
  Pizza *pizza {new CheesePizza};
  return pizza;
}
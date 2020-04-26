/**
 * @file veggie_pizza_factory.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "veggie_pizza_factory.h"
#include "../pizza/veggie_pizza.h"

Pizza * VeggiePizzaFactory::CreatePizza() {
  Pizza *pizza {new VeggiePizza};
  return pizza;
}
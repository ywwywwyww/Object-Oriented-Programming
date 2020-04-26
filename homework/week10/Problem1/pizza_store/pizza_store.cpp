/**
 * @file pizza_store.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "pizza_store.h"

Pizza *PizzaStore::OrderPizza(PizzaFactory *factory) {
  Pizza *pizza{factory->CreatePizza()};
  return pizza;
}
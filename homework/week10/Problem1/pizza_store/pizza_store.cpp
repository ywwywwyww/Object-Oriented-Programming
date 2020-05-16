/**
 * @file pizza_store.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "pizza_store.h"

std::shared_ptr<Pizza> PizzaStore::OrderPizza(std::shared_ptr<PizzaFactory> factory) {
  std::shared_ptr<Pizza> pizza{factory->CreatePizza()};
  return pizza;
}
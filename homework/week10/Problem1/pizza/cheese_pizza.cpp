/**
 * @file cheese_pizza.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "cheese_pizza.h"

void CheesePizza::SellPizza(std::ostream &out) {
  out << "sell a cheese pizza with id: " << this->id_ << std::endl;
}
/**
 * @file pizza_heap.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "pizza_heap.h"

PizzaHeap::PizzaHeap(Sorter *sorter) : sorter_{sorter} {}

void PizzaHeap::Insert(Pizza *pizza) {
  this->pizzas_.push_back(pizza);
}

void PizzaHeap::Display(std::ostream &out) {
  out << "Pizzas:\n";
  for (auto pizza : this->pizzas_) {
    pizza->SellPizza(out);
  }
  out << std::endl;
}

void PizzaHeap::Sort() {
  this->sorter_->Sort(this->pizzas_);
}
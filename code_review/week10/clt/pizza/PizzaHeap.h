#ifndef PIZZAHEAP_H_
#define PIZZAHEAP_H_

#include <iostream>
#include <vector>

#include "Pizza.h"
#include "Sort.h"

class PizzaHeap {
 private:
  std::vector<Pizza*>* pizzas_;
  Sort* sort_pizza_;

 public:
  PizzaHeap(Sort* sort_pizza) : sort_pizza_(sort_pizza) {
    pizzas_ = new std::vector<Pizza*>();
  }
  void add_pizza(Pizza* pizza) { pizzas_->push_back(pizza); }
  void sort_pizza() { sort_pizza_->sorting(pizzas_); }
  void show_pizza() {
    for (auto i : *pizzas_) {
      std::cout << "Pizza id: " << i->get_id() << "\n";
    }
  }
  virtual ~PizzaHeap() { delete pizzas_; }
};

#endif /* PIZZAHEAP_H_ */
#include <iostream>
#include "pizza/pizza.h"
#include "pizza_store/pizza_store.h"
#include "pizza_factory/cheese_pizza_factory.h"
#include "pizza_factory/veggie_pizza_factory.h"

void TestFactory() {
  PizzaStore *store {new PizzaStore};
  PizzaFactory *factory {new CheesePizzaFactory};

  store->OrderPizza(factory)->SellPizza();
  delete factory;

  factory = new VeggiePizzaFactory;
  store->OrderPizza(factory)->SellPizza();

  delete factory;
  delete store;
}

int main() {
  TestFactory();
  return 0;
}

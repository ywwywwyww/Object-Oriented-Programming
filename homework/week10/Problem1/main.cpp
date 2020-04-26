#include <iostream>
#include "pizza/pizza.h"
#include "pizza_store/pizza_store.h"
#include "pizza_factory/cheese_pizza_factory.h"
#include "pizza_factory/veggie_pizza_factory.h"
#include "sorter/custom_sorter.h"
#include "pizza_heap/pizza_heap.h"
#include "sorter/stl_sort_sorter.h"
#include "sorter/stl_priority_queue_sorter.h"
#include "generator/generator.h"
#include "timer/timer.h"

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

template<typename T>
double Time(T heap) {
  Timer timer;
  timer.start();
  heap->Sort();
  timer.stop();
  return timer.time();
}

void TestSort() {
  auto store {new PizzaStore};
  auto cheese_factory {new CheesePizzaFactory};
  auto veggie_factory {new VeggiePizzaFactory};

  auto modest_heap {new PizzaHeap {new StlSortSorter {}}};
  auto handsome_heap {new PizzaHeap {new CustomSorter {}}};
  auto honest_heap {new PizzaHeap {new StlPriorityQueueSorter {}}};
  const int kCheesePizzaCnt = 500, kVeggiePizzaCnt = 500;
  for (int i = 0; i < kCheesePizzaCnt; i++) {
    modest_heap->Insert(store->OrderPizza(cheese_factory));
    handsome_heap->Insert(store->OrderPizza(cheese_factory));
    honest_heap->Insert(store->OrderPizza(cheese_factory));
  }
  for (int i = 0; i < kVeggiePizzaCnt; i++) {
    modest_heap->Insert(store->OrderPizza(veggie_factory));
    handsome_heap->Insert(store->OrderPizza(veggie_factory));
    honest_heap->Insert(store->OrderPizza(veggie_factory));
  }
  std::cout << "STL sort time: " << Time(modest_heap) << "s" << std::endl;
  std::cout << "Custom sort time: " << Time(handsome_heap) << "s" << std::endl;
  std::cout << "STL priority queue time: " << Time(honest_heap) << "s" << std::endl;
//  honest_heap->Display();
}

int main() {
//  TestFactory();
  TestSort();
  return 0;
}

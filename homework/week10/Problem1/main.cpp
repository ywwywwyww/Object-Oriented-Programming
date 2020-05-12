#include <iostream>
#include "pizza/pizza.h"
#include "pizza_store/pizza_store.h"
#include "pizza_factory/cheese_pizza_factory.h"
#include "pizza_factory/veggie_pizza_factory.h"
#include "sorter/custom_sorter.h"
#include "pizza_heap/pizza_heap.h"
#include "sorter/stl_sort_sorter.h"
#include "sorter/stl_priority_queue_sorter.h"
#include "timer/timer.h"

/**
 * Tests the pizza factory and pizza store class
 */
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

/**
 * Times the time of heap
 * @tparam T
 * @param heap
 * @return Runtime
 */
template<typename T>
double Time(T heap) {
  Timer timer;
  timer.start();
  heap->Sort();
  timer.stop();
  return timer.time();
}

/**
 * Tests the sorter class and heap class
 */
void TestSort() {
  auto store {new PizzaStore};
  auto cheese_factory {new CheesePizzaFactory};
  auto veggie_factory {new VeggiePizzaFactory};

  auto modest_heap {new PizzaHeap {new StlSortSorter {}}};
  auto handsome_heap {new PizzaHeap {new CustomSorter {}}};
  auto honest_heap {new PizzaHeap {new StlPriorityQueueSorter {}}};

  const int kCheesePizzaCnt = 500, kVeggiePizzaCnt = 500;

  // Insert pizzas
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

  // Sort and time
  std::cout << "STL sort time: " << Time(modest_heap) << "s" << std::endl;
  std::cout << "Custom sort time: " << Time(handsome_heap) << "s" << std::endl;
  std::cout << "STL priority queue time: " << Time(honest_heap) << "s" << std::endl;

  // Display the results
//  honest_heap->Display();

  delete store;
  delete cheese_factory;
  delete veggie_factory;
  delete modest_heap;
  delete handsome_heap;
  delete honest_heap;
}

int main() {
//  TestFactory();
  TestSort();
  return 0;
}

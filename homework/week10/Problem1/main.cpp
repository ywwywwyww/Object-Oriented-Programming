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
#include <memory>

/**
 * Tests the pizza factory and pizza store class
 */
void TestFactory() {
  std::shared_ptr<PizzaStore> store{new PizzaStore};
  std::shared_ptr<PizzaFactory> factory{new CheesePizzaFactory};

  store->OrderPizza(factory)->SellPizza();

  factory.reset(new VeggiePizzaFactory);
  store->OrderPizza(factory)->SellPizza();
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
  std::shared_ptr<PizzaStore> store{new PizzaStore};
  std::shared_ptr<CheesePizzaFactory> cheese_factory{new CheesePizzaFactory};
  std::shared_ptr<VeggiePizzaFactory> veggie_factory{new VeggiePizzaFactory};

  std::shared_ptr<PizzaHeap> modest_heap{new PizzaHeap{std::make_shared<StlSortSorter>()}};
  std::shared_ptr<PizzaHeap> handsome_heap{new PizzaHeap{std::make_shared<CustomSorter>()}};
  std::shared_ptr<PizzaHeap> honest_heap{new PizzaHeap{std::make_shared<StlPriorityQueueSorter>()}};

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
}

int main() {
//  TestFactory();
  TestSort();
  return 0;
}

#include <ctime>
#include <iostream>

#include "AdapterSort.h"
#include "CheesePizzaFactory.h"
#include "PizzaHeap.h"
#include "STLSort.h"
#include "SelfSort.h"
#include "VeggiePizzaFactory.h"
#include "timer.h"

constexpr int M = 500;  // create M pieces of each kind of pizza

int main() {
  srand(time(nullptr));
  Factory* cheese_pizza_factory = new CheesePizzaFactory();
  Factory* veggie_pizza_factory = new VeggiePizzaFactory();

  Timer timer{};

  /******************* SelfSort Test Begins *******************/

  Sort* self_sort = new SelfSort();
  PizzaHeap* pizza_heap_self = new PizzaHeap{self_sort};
  for (int i = 0; i < M; ++i)
    pizza_heap_self->add_pizza(cheese_pizza_factory->making());
  for (int i = 0; i < M; ++i)
    pizza_heap_self->add_pizza(veggie_pizza_factory->making());

  std::cout << "Sorted: \n";
  {  // do the sorting
    timer.start();
    pizza_heap_self->sort_pizza();
    timer.stop();
    std::cout << "Time wasted using SelfSort: " << timer.time() * 1000
              << " ms\n";
  }
  pizza_heap_self->show_pizza();

  /******************** SelfSort Test Ends ********************/

  /****************** AdapterSort Test Begins *****************/

  Sort* adapter_sort = new AdapterSort();
  PizzaHeap* pizza_heap_adapter = new PizzaHeap{adapter_sort};
  for (int i = 0; i < M; ++i)
    pizza_heap_adapter->add_pizza(cheese_pizza_factory->making());
  for (int i = 0; i < M; ++i)
    pizza_heap_adapter->add_pizza(veggie_pizza_factory->making());

  std::cout << "Sorted: \n";
  {
    timer.reset();
    timer.start();
    pizza_heap_adapter->sort_pizza();
    timer.stop();
    std::cout << "Time wasted using AdapterSort: " << timer.time() * 1000
              << " ms\n";
  }
  pizza_heap_adapter->show_pizza();

  /******************* AdapterSort Test Ends ******************/

  /******************** STLSort Test Begins *******************/

  Sort* stl_sort = new STLSort();
  PizzaHeap* pizza_heap_stl = new PizzaHeap{stl_sort};
  for (int i = 0; i < M; ++i)
    pizza_heap_stl->add_pizza(cheese_pizza_factory->making());
  for (int i = 0; i < M; ++i)
    pizza_heap_stl->add_pizza(veggie_pizza_factory->making());

  std::cout << "Sorted: \n";
  {
    timer.reset();
    timer.start();
    pizza_heap_stl->sort_pizza();
    timer.stop();
    std::cout << "Time wasted using STLSort: " << timer.time() * 1000
              << " ms\n";
  }
  pizza_heap_stl->show_pizza();

  /********************* STLSort Test Ends ********************/

  return 0;
}
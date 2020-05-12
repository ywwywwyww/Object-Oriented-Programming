///////////////////////////////////////////////////////////////////////////////
//File: PizzaHeap.h
//Description: Declaration of Class PizzaHeap
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_PIZZAHEAP_H_
#define PIZZA_PIZZAHEAP_H_

#include "Pizza.h"
#include "SortStrategy.h"

#include <string>
#include <vector>

const int kPizzaNumber = 600;
//The number of Veggie & Cheese pizza respectively

class PizzaHeap {
private:
	std:: vector <Pizza*> vector_pizza;//The pizzas waiting to sort
	SortStrategy *sort_pizza;//The type of sorting algorithm
public:
	PizzaHeap(SortStrategy *strategy);
	~PizzaHeap();
	void SortPizza();
};

#endif

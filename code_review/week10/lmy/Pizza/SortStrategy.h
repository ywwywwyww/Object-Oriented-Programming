///////////////////////////////////////////////////////////////////////////////
//File: SortStrategy.h
//Description: Declaration of Class SortStrategy
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_SORTSTRATEGY_H_
#define PIZZA_SORTSTRATEGY_H_

#include "Pizza.h"

#include <vector>

class SortStrategy {
public:
	SortStrategy() = default;
	virtual ~SortStrategy() = default;
	virtual void SortAllPizza(std::vector <Pizza*>& vector_pizza) = 0;//Sort all pizzas
};

#endif


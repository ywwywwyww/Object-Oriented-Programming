///////////////////////////////////////////////////////////////////////////////
//File: Honest.h
//Description: The header file for priority queue sort
//////////////////////////////////////////////////////////////////////////////
#ifndef PIZZA_HONEST_H_
#define PIZZA_HONEST_H_

#include "Pizza.h"
#include "SortStrategy.h"

#include <vector>

//Adapter for SortStrategy using priority queue
class Honest: public SortStrategy {
public:
	Honest() = default;
	~Honest() = default;
	void SortAllPizza(std::vector <Pizza*>& vector_pizza);
};

#endif

///////////////////////////////////////////////////////////////////////////////
//File: Modest.h
//Description: The header file for <algorithm> sort
//////////////////////////////////////////////////////////////////////////////
#ifndef PIZZA_MODEST_H_
#define PIZZA_MODEST_H_

#include "Pizza.h"
#include "SortStrategy.h"

#include <vector>

//Comparison by alphabetic order
bool cmp(Pizza* a, Pizza* b);

//Use <algorithm> sort to sort pizza
class Modest: public SortStrategy {
public:
	Modest() = default;
	~Modest() = default;
	void SortAllPizza(std::vector <Pizza*>& vector_pizza);
};

#endif

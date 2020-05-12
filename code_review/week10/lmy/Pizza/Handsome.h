///////////////////////////////////////////////////////////////////////////////
//File: Handsome.h
//Description: The header file for BubbleSort algorithm sorting vectors
//////////////////////////////////////////////////////////////////////////////
#ifndef PIZZA_HANDSOME_H_
#define PIZZA_HANDSOME_H_

#include "Pizza.h"
#include "SortStrategy.h"

#include <vector>

//Use bubble sort to sort pizza
class Handsome: public SortStrategy {
public:
	Handsome() = default;
	~Handsome() = default;
	void SortAllPizza(std::vector <Pizza*>& vector_pizza);//Sort by bubblesort
};

#endif

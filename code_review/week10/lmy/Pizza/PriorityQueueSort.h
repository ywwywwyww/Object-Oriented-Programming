///////////////////////////////////////////////////////////////////////////////
//File: PriorityQueueSort.h
//Description: The header file for the adapter class PriorityQueueSort 
//for sorting pizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_PRIORITYQUEUESORT_H_
#define PIZZA_PRIORITYQUEUESORT_H_

#include "SortStrategy.h"

#include "Pizza.h"

#include <iostream>
#include <queue>
#include <vector>

struct cmp{
	bool operator () (const Pizza* a, const Pizza* b) {
		for(int i=0; i<kIdLength; i++) {
			if((a->id[i]) != (b->id[i]) )
				return (a->id[i]) > (b->id[i]);
		}
		return false;
	}
};

class PriorityQueueSort: public SortStrategy {
private:
	std::priority_queue <Pizza*, std::vector <Pizza*>, cmp> queue_sort_pizza;
public:
	PriorityQueueSort() {
		while (!queue_sort_pizza.empty())
			queue_sort_pizza.pop();
	}
	~PriorityQueueSort() {
		while (!queue_sort_pizza.empty())
			queue_sort_pizza.pop();
	}
	void SortAllPizza(std::vector <Pizza*>& vector_pizza);
};

#endif

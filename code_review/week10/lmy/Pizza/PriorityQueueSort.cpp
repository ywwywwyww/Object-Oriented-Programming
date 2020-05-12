///////////////////////////////////////////////////////////////////////////////
//File: PriorityQueueSort.cpp
//Description: The implementation for function SortAllPizza by priority_queue
//in the adapter class PriorityQueueSort for sorting pizza
///////////////////////////////////////////////////////////////////////////////

#include "PriorityQueueSort.h"

#include "Pizza.h"

#include <queue>

using namespace std;

void PriorityQueueSort::SortAllPizza(vector <Pizza*>& vector_pizza) {
	for(int i=0; i<vector_pizza.size(); i++) {
		queue_sort_pizza.push(vector_pizza[i]);
	}
	for(int i=0; i<vector_pizza.size(); i++) {
		vector_pizza[i]=queue_sort_pizza.top();
		queue_sort_pizza.pop();
	}
}

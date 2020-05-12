///////////////////////////////////////////////////////////////////////////////
//File: Honest.h
//Description: The implementation of priority queue sort
//////////////////////////////////////////////////////////////////////////////

#include "Honest.h"

#include "Pizza.h"
#include "PriorityQueueSort.h"

#include <ctime>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Sort vector_pizza by Bubble Sort
void Honest::SortAllPizza(vector <Pizza*>& vector_pizza) {
	int start_time=clock();
	PriorityQueueSort *pizza_sort {new PriorityQueueSort};
	pizza_sort->SortAllPizza(vector_pizza);
	int end_time=clock(), runtime=end_time-start_time;
	printf("Honest consumes %.2lf ms\n", double(runtime)/CLOCKS_PER_SEC*1000.0);
	//runtime is the cpu clock time not second so runtime need some conversion
}

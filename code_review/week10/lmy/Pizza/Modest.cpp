///////////////////////////////////////////////////////////////////////////////
//File: Modest.cpp
//Description: The implementation for <algorithm> sort to sort vectors
///////////////////////////////////////////////////////////////////////////////

#include "Modest.h"

#include "Compare.h"
#include "Pizza.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

//Sort vector_pizza by Bubble Sort
void Modest::SortAllPizza(vector <Pizza*>& vector_pizza) {
	int start_time=clock();
	sort(vector_pizza.begin(), vector_pizza.end(), Compare );
	int end_time=clock(), runtime=end_time-start_time;
	printf("Modest consumes %.2lf ms\n", double(runtime)/CLOCKS_PER_SEC*1000.0);
	//runtime is the cpu clock time not second so runtime need some conversion
}

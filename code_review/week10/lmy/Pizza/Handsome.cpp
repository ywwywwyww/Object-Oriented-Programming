///////////////////////////////////////////////////////////////////////////////
//File: Handsome.cpp
//Description: The implementation for BubbleSort algorithm sorting vectors
///////////////////////////////////////////////////////////////////////////////

#include "Handsome.h"

#include "Compare.h"
#include "Pizza.h"

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

//Sort vector_pizza by Bubble Sort
void Handsome::SortAllPizza(vector <Pizza*>& vector_pizza) {
	int start_time=clock();
	Pizza temp;
	for(int i=0; i<vector_pizza.size(); i++) {
		for(int j=i+1; j<vector_pizza.size(); j++) {
			if(!Compare(vector_pizza[i], vector_pizza[j]) )
				swap(vector_pizza[i], vector_pizza[j]);
		}
	}
	int end_time=clock(), runtime=end_time-start_time;
	printf("Handsome consumes %.2lf ms\n", double(runtime)/CLOCKS_PER_SEC*1000.0);
	//runtime is the cpu clock time not second so runtime need some conversion
}

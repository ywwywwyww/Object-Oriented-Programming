///////////////////////////////////////////////////////////////////////////////
//File: main.cpp
//Description: Test all three types of sort algorithms for pizza
///////////////////////////////////////////////////////////////////////////////

#include "Pizza.h"
#include "CheesePizza.h"
#include "VeggiePizza.h"
#include "SortStrategy.h"
#include "Modest.h"
#include "Handsome.h"
#include "Honest.h"
#include "PizzaHeap.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
	srand(unsigned(time(0)));
	SortStrategy *modest {new Modest};
	SortStrategy *handsome {new Handsome};
	SortStrategy *honest {new Honest};
	PizzaHeap *modest_heap {new PizzaHeap(modest)};
	PizzaHeap *handsome_heap {new PizzaHeap(handsome)};
	PizzaHeap *honest_heap {new PizzaHeap(honest)};
	
	modest_heap->SortPizza();
	handsome_heap->SortPizza();
	honest_heap->SortPizza();
	
	delete modest_heap;
	delete handsome_heap;
	delete honest_heap;
	return 0;
}

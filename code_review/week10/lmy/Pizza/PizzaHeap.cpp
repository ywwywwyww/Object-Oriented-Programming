///////////////////////////////////////////////////////////////////////////////
//File: PizzaHeap.cpp
//Description: Definition of Class PizzaHeap
///////////////////////////////////////////////////////////////////////////////

#include "PizzaHeap.h"

#include "Pizza.h"
#include "PizzaFactory.h"
#include "CheesePizzaFactory.h"
#include "VeggiePizzaFactory.h"
#include "SortStrategy.h"

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

PizzaHeap::PizzaHeap (SortStrategy *strategy): sort_pizza{strategy} {
	vector_pizza.clear();
	PizzaFactory *cheese_factory {new CheesePizzaFactory};
	PizzaFactory *veggie_factory {new VeggiePizzaFactory};
	for(int i=1; i<=kPizzaNumber; i++) {
		vector_pizza.push_back(cheese_factory -> CreatePizza() );
		vector_pizza.push_back(veggie_factory -> CreatePizza() );
	}
}

PizzaHeap::~PizzaHeap() {
	vector_pizza.clear();
}

void PizzaHeap::SortPizza() {
	sort_pizza -> SortAllPizza(vector_pizza);
}

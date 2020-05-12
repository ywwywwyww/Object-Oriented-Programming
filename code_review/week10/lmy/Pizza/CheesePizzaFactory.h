///////////////////////////////////////////////////////////////////////////////
//File: CheesePizzaFactory.h
//Description: Declaration of Basic Class CheesePizzaFactory to create class
//CheesePizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_CHEESEPIZZAFACTORY_H_
#define PIZZA_CHEESEPIZZAFACTORY_H_

#include "PizzaFactory.h"

#include "CheesePizza.h"

class CheesePizzaFactory : public PizzaFactory {
public:
	CheesePizzaFactory() = default;
	~CheesePizzaFactory() = default;
	Pizza *CreatePizza() {
		Pizza *pizza { new CheesePizza{} };
		return pizza;
	}
};

#endif

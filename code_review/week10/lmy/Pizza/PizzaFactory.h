///////////////////////////////////////////////////////////////////////////////
//File: PizzaFactory.h
//Description: Declaration of Class PizzaFactory
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_PIZZAFACTORY_H_
#define PIZZA_PIZZAFACTORY_H_

#include "Pizza.h"

class PizzaFactory {
public:
	PizzaFactory() = default;
	virtual ~PizzaFactory() = default;
	virtual Pizza *CreatePizza() = 0;//Create a Pizza Class
};

#endif

///////////////////////////////////////////////////////////////////////////////
//File: VeggiePizzaFactory.h
//Description: Declaration of Basic Class VeggiePizzaFactory to create class
//VeggiePizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_VEGGIEPIZZAFACTORY_H_
#define PIZZA_VEGGIEPIZZAFACTORY_H_

#include "PizzaFactory.h"

#include "VeggiePizza.h"

class VeggiePizzaFactory : public PizzaFactory {
public:
	VeggiePizzaFactory() = default;
	~VeggiePizzaFactory() = default;
	Pizza *CreatePizza() {
		Pizza *pizza { new VeggiePizza{} };
		return pizza;
	}
};

#endif

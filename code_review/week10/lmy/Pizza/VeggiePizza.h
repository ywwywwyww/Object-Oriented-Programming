///////////////////////////////////////////////////////////////////////////////
//File: CheesePizza.h
//Description: Declaration of Basic Class CheesePizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_VEGGIEPIZZA_H_
#define PIZZA_VEGGIEPIZZA_H_

#include "Pizza.h"

class VeggiePizza : public Pizza {
public:
	VeggiePizza(): Pizza() {}
	~VeggiePizza() = default;
};

#endif

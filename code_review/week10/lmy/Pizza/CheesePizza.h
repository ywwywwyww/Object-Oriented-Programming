///////////////////////////////////////////////////////////////////////////////
//File: CheesePizza.h
//Description: Declaration of Basic Class CheesePizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_CHEESEPIZZA_H_
#define PIZZA_CHEESEPIZZA_H_

#include "Pizza.h"

class CheesePizza : public Pizza {
public:
	CheesePizza(): Pizza() {}
	~CheesePizza() = default;
};

#endif

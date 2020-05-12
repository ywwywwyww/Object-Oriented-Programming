///////////////////////////////////////////////////////////////////////////////
//File: Pizza.h
//Description: Declaration of Class Pizza
///////////////////////////////////////////////////////////////////////////////

#ifndef PIZZA_PIZZA_H_
#define PIZZA_PIZZA_H_

#include <map>

extern std::map <unsigned long long, bool> map_hash_id;

const int kIdLength = 16;
//Ensure every pizza has unique id. Store the Hash code of id
const int kHashMul = 197;//a prime constant for generating hash code

class Pizza {
public:
	char *id;
	Pizza();
	virtual ~Pizza();
};

#endif

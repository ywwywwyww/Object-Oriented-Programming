///////////////////////////////////////////////////////////////////////////////
//File: Compare.cpp
//Description: Defintion for Compare function of Pizza*
//////////////////////////////////////////////////////////////////////////////

#include "Compare.h"
#include "Pizza.h"

//Comparison by alphabetic order
//Comparison by alphabetic order
bool Compare(Pizza* a, Pizza* b) {
	for(int i=0; i<kIdLength; i++) {
		if((a->id[i]) != (b->id[i]) )
			return (a->id[i]) < (b->id[i]);
	}
	return false;
}

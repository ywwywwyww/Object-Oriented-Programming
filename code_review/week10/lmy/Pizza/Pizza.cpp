///////////////////////////////////////////////////////////////////////////////
//File: Pizza.cpp
//Description: Definition of Constructor & Destructor for Class Pizza
///////////////////////////////////////////////////////////////////////////////

#include "Pizza.h"

#include <cstdlib>
#include <map>

using namespace std;

map <unsigned long long, bool> map_hash_id;
//Constructor
Pizza::Pizza() {
	id=new char [kIdLength + 5];
	id[kIdLength]=id[kIdLength+1]=0;
	while (true) {
		unsigned long long hash_id=0;
		for(int i=0; i<kIdLength; i++) {
			int x = rand()%36;
			id[i] = x>=26? '0'+x-26 : 'a'+x;
			//generate an a~z charater when x<=25 while generate 0~9 when x>=26
			hash_id=hash_id * kHashMul + x;//generate the hash code of id
		}
		if(map_hash_id.find(hash_id)!=map_hash_id.end() )
			continue;
		map_hash_id[hash_id] = true;
		break;
	}
}

//Destructor
Pizza::~Pizza() {
	delete [] id;
}

#include "ObjNum.h"

#include <cstdio>
#include <iostream>

int main() {
	A::printObjNum();
    A a(5);
	A::printObjNum();
    A b = a;
	A::printObjNum();
	
    a.print();
    b.print();
    b.set(2, 10);
    b.print();
    a.print();
	
	A *temp=new A(5);
	A::printObjNum();
	delete temp;
	A::printObjNum();
	return 0;
}

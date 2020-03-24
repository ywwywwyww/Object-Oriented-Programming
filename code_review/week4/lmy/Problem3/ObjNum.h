#ifndef PROBLEM3_OBJNUM_H_
#define PROBLEM3_OBJNUM_H_

#include <cstring>
#include <iostream>

using namespace std;

class A {
    int *m_arr;
    int m_size;
	static int object_count;//Store the number of objects
public:
	A(int i):m_size{i} {
        m_arr = new int[m_size];
        std::memset(m_arr, 0, m_size*sizeof(int));
		object_count++;//A new object is defined
    }
	A(const A &c);//Copy constructor
    ~A() {
		delete []m_arr;
		object_count--;//An object is deleted
	}
    void set(int index, int value) {
        m_arr[index] = value;
    }
    void print();
	static void printObjNum();
};

#endif

#include "ObjNum.h"

#include <cstdio>
#include <iostream>

int A::object_count=0;

A::A(const A &copy_object):m_size{copy_object.m_size} {//Copy Constructor
	m_arr=new int[m_size];
	for(int i=0;i<m_size;i++)
		m_arr[i]=copy_object.m_arr[i];
	object_count++;//A new object is copied
}

void A::print() {
	std::cout << "m_arr: ";
    for (int i = 0; i < m_size; ++ i)
    {
		std::cout << " " << m_arr[i];
    }
	std::cout << std::endl;
}

void A::printObjNum() {
	std::cout<<"Number of Object: "<<A::object_count<<std::endl;
}

//
//  A.cpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#include "A.hpp"
#include <cstring>

int A::obj_num=0;

//constructor
A::A(int i):m_size(i){
    m_arr = new int[m_size];
    memset(m_arr, 0, m_size*sizeof(int));
    obj_num++;
}

//copy constructor
A::A(A& a){
    this->m_size=a.m_size;
    this->m_arr = new int[m_size];
    for(int i = 0; i < m_size; i++)
        this->m_arr[i] = a.m_arr[i];
    obj_num++;
}

//destructor
A::~A(){
    delete [] m_arr;
    obj_num--;
}

void A::print()
{
    cout << "m_arr: ";
    for (int i = 0; i < m_size; ++ i)
    {
        cout << " " << m_arr[i];
    }
    cout << endl;
}

void A::printObjNum()
{
    cout <<  "The number of the current existing objects is "<< obj_num << endl;
}

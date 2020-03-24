//
//  A.hpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#ifndef A_hpp
#define A_hpp

#include <iostream>
using namespace std;

class A{
private:
    static int obj_num;
    int* m_arr;
    int m_size;
public:
    A(int i);//constructor
    A(A& i);//copy constructor
    ~A();//destructor
    void set(int index, int value){m_arr[index] = value;};
    void print();
    void printObjNum();
};



#endif /* A_hpp */

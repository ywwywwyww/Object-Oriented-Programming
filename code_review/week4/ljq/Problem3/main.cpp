//
//  main.cpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#include <iostream>
#include "A.hpp"
using namespace std;

int main()
{
    A a(5);
    a.printObjNum();
    A b = a;
    a.print();
    b.print();
    b.set(2, 10);
    b.print();
    a.print();
    a.printObjNum();
    A* c = new A(a);
    c->printObjNum();
    delete c;
    a.printObjNum();
}


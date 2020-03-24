//
//  main.cpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
    Matrix a("a.txt"), b; //a.txt stores a matrix of 6 rows and 8 columns
    b.load("b.txt"); //b.txt stores a matrix of 8 rows and 6 columns
    a.display(); //print matrix a
    b.display(); //print matrix b
    Matrix c;
    c = a.multiply(b);//compute the product
    c.display(); //print the product
    c.save("c.txt"); //save a matrix of 6 rows and 6 columns
    
    return 0;
}

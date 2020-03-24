//
//  Matrix.hpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix{
private:
    int row, column;
    vector<vector<int> > matrix;
public:
    Matrix():row(0), column(0){};//default constructor
    Matrix(string file);//constructor
    Matrix(Matrix& mat);//copy constructor
    void load(string file);
    void display();
    Matrix multiply(Matrix b);
    void save(string file);
    Matrix& operator=(const Matrix& mat);
};

#endif /* Matrix_hpp */

//
//  Matrix.cpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

Matrix::Matrix(string file)//constructor
{
    ifstream fin(file);
    
    fin >> row >> column;
    matrix.resize(row);
    for(int i = 0; i < row ; i++)
        matrix[i].resize(column);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            fin >> matrix[i][j];
}

Matrix::Matrix(Matrix& mat)//copy constructor
{
    this->row = mat.row;
    this->column = mat.column;
    this->matrix.resize(row);
    for(int i = 0; i < row ; i++)
        this->matrix[i].resize(column);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            this->matrix[i][j] = mat.matrix[i][j];
}

void Matrix::load(string file)
{
    ifstream fin(file);
    
    fin >> row >> column;
    matrix.resize(row);
    for(int i = 0; i < row ; i++)
        matrix[i].resize(column);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            fin >> matrix[i][j];
}

void Matrix::display()
{
    cout << this->row << ' ' << this->column << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            cout << this->matrix[i][j] << ' ';
        cout << endl;
    }
}

Matrix Matrix::multiply(Matrix b)
{
    assert(b.row == this -> column);
    Matrix ans;
    ans.row = this -> row;
    ans.column = b.column;
    ans.matrix.resize(this -> row);
    for(int i = 0; i < row ; i++)
        ans.matrix[i].resize(b.column);
    
    for(int i = 0; i < this -> row; i++)
        for(int j = 0; j < this -> column; j++)
        {
            ans.matrix[i][j] = 0;
            for(int k = 0; k < this -> column; k++)
                ans.matrix[i][j] += this -> matrix[i][k] * b.matrix[k][j];
        }
    
    return ans;
                
}

void Matrix::save(string file)
{
    ofstream fout(file);
    
    fout << row << ' ' << column << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            fout << matrix[i][j] << ' ';
        fout << endl;
    }
}

Matrix& Matrix::operator=(const Matrix& mat)
{
    if(this != &mat)
    {
        this->row = mat.row;
        this->column = mat.column;
        this->matrix.resize(this->row);
        for(int i = 0; i < this->row; i++)
            this->matrix[i].resize(this->column);
    }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            this->matrix[i][j] = mat.matrix[i][j];
    
    return *this;
}

#ifndef PROBLEM2_MATRIX_H_
#define PROBLEM2_MATRIX_H_

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

class Matrix {
	int Row, Column;
	std::vector< std::vector<int> > Element;//Element stores the elements in the matrix
	
	void Initialize(const int Row_,const int Column_);//Initialize the size of Element

	public:
		Matrix()=default;
		//Copy constructor
		Matrix(const Matrix &matrix);
		//Constructor with file name
	
		Matrix(const std::string &file);
		void load(const std::string &file);
		void save(const std::string &file);
		void display();
		Matrix multiply(const Matrix &matrix);
	
		//Deconstructor
		~Matrix();
};

#endif

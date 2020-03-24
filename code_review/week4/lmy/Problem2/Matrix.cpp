#include "Matrix.h"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Matrix::Matrix(const std::string &file) {
	load(file);
}

void Matrix::Initialize(const int Row_,const int Column_) {
	Row=Row_,Column=Column_;

	Element.resize(Row+1);
	for(int i=0;i<=Row;i++) {
		Element[i].resize(Column+1);
	}
}

Matrix::Matrix(const Matrix &matrix) {
	Initialize(matrix.Row,matrix.Column);//Initialize the matrix

	for(int i=1;i<=Row;i++) {
		for(int p=1;p<=Column;p++) {
			Element[i][p]=matrix.Element[i][p];//Copy the elements
		}
	}
	printf("Copied!\n");
}

void Matrix::load(const std::string &file) {
	std::ifstream fin(file);
	fin>>Row>>Column;
	Initialize(Row,Column);//Initialize the matrix

	for(int i=1;i<=Row;i++) {
		for(int p=1;p<=Column;p++) {
			fin>>Element[i][p];
		}
	}
	fin.close();
}

void Matrix::save(const std::string &file) {
	std::ofstream fout(file);
	fout<<Row<<" "<<Column<<std::endl;
	for(int i=1;i<=Row;i++) {
		for(int p=1;p<=Column;p++) {
			fout<<Element[i][p]<<" ";
		}
		fout<<std::endl;
	}
	fout.close();
}

void Matrix::display() {
	std::cout<<Row<<" "<<Column<<std::endl;
	for(int i=1;i<=Row;i++) {
		for(int p=1;p<=Column;p++) {
			std::cout<<Element[i][p]<<" ";
		}
		std::cout<<std::endl;
	}
}

Matrix Matrix::multiply(const Matrix &matrix) {
	static Matrix ans;//Store the multiplication
	ans.Initialize(Row,matrix.Column);

	for(int i=1;i<=ans.Row;i++) {
		for(int p=1;p<=ans.Column;p++) {
			ans.Element[i][p]=0;
			for(int k=1;k<=Column;k++){
				ans.Element[i][p]+=Element[i][k]*matrix.Element[k][p];//The dot product of the i^th row of Element and p^th column of matrix.Element
			}
		}
	}

	return ans;
}

Matrix::~Matrix() {
	Element.clear();
}

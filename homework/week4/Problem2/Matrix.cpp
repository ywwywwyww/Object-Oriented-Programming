/**
 * @file Matrix.cpp
 * @author Wuwei YUAN
 * @date 3/14/20
 */

#include "Matrix.h"
#include <fstream>

void Matrix::load(const std::string &file_name) {
  int num_rows, num_cols;
  std::ifstream fin{file_name};
  fin >> num_rows >> num_cols;
  data_.resize(num_rows, std::vector<int>(num_cols));
  for (auto &row : data_) {
    for (auto &element : row) {
      fin >> element;
    }
  }
}

void Matrix::Output(std::ostream &output_stream) const {
  // Do not flush frequently in order to improve performance
  output_stream << GetNumberOfRows() << ' ' << GetNumberOfColumns() << '\n';
  for (auto &row : data_) {
    for (auto &element : row) {
      output_stream << element << ' ';
    }
    output_stream << '\n';
  }
  output_stream << std::flush;
}

void Matrix::save(const std::string &file_name) const {
  std::ofstream fout{file_name};
  Output(fout);
}

void Matrix::display() const {
  Output(std::cout);
}

Matrix Matrix::multiply(const Matrix &b) const {
  const Matrix &a = *this;
  int num_rows_a = a.GetNumberOfRows();
  int num_cols_a = a.GetNumberOfColumns();
  int num_rows_b = b.GetNumberOfRows();
  int num_cols_b = b.GetNumberOfColumns();
  // The number of rows of b must be equal to the number of columns of a
  if (num_cols_a != num_rows_b) {
    std::cerr << "ERROR : "
              << "the number of rows of the second matrix must be equal to the number of columns of the first matrix"
              << std::endl;
    // Otherwise return an empty matrix
    return Matrix();
  }
  // Compute the product
  Matrix result(num_rows_a, num_cols_b);
  for (int i = 0; i < num_rows_a; i++) {
    for (int k = 0; k < num_cols_b; k++) {
      for (int j = 0; j < num_cols_a; j++) {
        result.data_[i][k] += a.data_[i][j] * b.data_[j][k];
      }
    }
  }
  return result;
}

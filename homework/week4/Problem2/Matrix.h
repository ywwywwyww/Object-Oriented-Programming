/**
 * @file Matrix.h
 * @author Wuwei YUAN
 * @date 3/14/20
 */

#ifndef PROBLEM2__MATRIX_H_
#define PROBLEM2__MATRIX_H_


#include <vector>
#include <iostream>

/**
 * A matrix
 * example:
 *     Matrix a{'a.txt'};
 *     a.display();
 *     a.save('a_backup.txt');
 */
class Matrix {
 public:
  /**
   * Initializes the object with empty matrix
   */
  Matrix() : data_{} {}

  /**
   * Initializes the object with matrix in the file
   * @param file_name File name of the matrix
   */
  Matrix(const std::string &file_name) : data_{} {
    load(file_name);
  }

  /**
   * Initializes the object with empty matrix of num_rows rows and num_cols columns
   * @param num_rows The number of rows of the matrix
   * @param num_cols The number of columns of the matrix
   */
  Matrix(const int &num_rows, const int &num_cols)
      : data_{(long unsigned int)(num_rows), std::vector<int>(num_cols)}{}

  /**
   * Initializes the object with the existing matrix
   * @param matrix The existing matrix
   */
  Matrix(const Matrix &matrix) : data_{matrix.data_} {
    std::cerr << "Vector copied" << std::endl;
  }

  /**
   * Initializes the object with the existing matrix without copying data
   * @param matrix The existing matrix
   */
  Matrix(Matrix &&matrix) : data_{std::move(matrix.data_)} {}

  /**
   * Gets the number of rows of the matrix
   * @return The number of rows
   */
  int GetNumberOfRows() const {
    return data_.size();
  }

  /**
   * Gets the number of columns of the matrix
   * @return The number of columns
   */
  int GetNumberOfColumns() const {
    if (data_.empty()) {
      return 0;
    }
    return data_[0].size();
  }

  /**
   * Loads the matrix from given file
   * @param file_name The file name of the matrix
   */
  void load(const std::string &file_name);

  /**
   * Outputs the matrix to given output stream
   * @param output_stream The output stream
   */
  void Output(std::ostream &output_stream) const;

  /**
   * Saves the matrix to given file
   * @param file_name The file name
   */
  void save(const std::string &file_name) const;

  /**
   * Displays the matrix to the screen
   */
  void display() const;

  /**
   * Computes the product of two matrices - *this and another matrix
   * @param b Another matrix
   * @return The product of two matrices
   */
  Matrix multiply(const Matrix &b) const;

 private:
  std::vector<std::vector<int> > data_; // The matrix
};

#endif //PROBLEM2__MATRIX_H_

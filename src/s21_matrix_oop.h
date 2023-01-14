#ifndef __S21MATRIXOOP_H__
#define __S21MATRIXOOP_H__

#include <cstring>
#include <iostream>  // директива препроцессора

class S21Matrix {
 private:
  // Attributes
  int _rows;
  int _cols;
  double* _matrix;  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();   // Default constructor
  ~S21Matrix();  // Destructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
};

#endif
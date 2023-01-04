#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _matrix = new double[_rows * _cols];
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
  _matrix = new double[_rows * _cols];
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other) {}

// Конструктор переноса
S21Matrix::S21Matrix(S21Matrix&& other) {}

// Деструктор
S21Matrix::~S21Matrix() {}
#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _matrix = new double[_rows * _cols];
}

S21Matrix::S21Matrix(int rows, int cols)
    : _rows(rows), _cols(cols) {  // инициализация по умолчанию
  _matrix = new double[_rows * _cols];
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : _rows(other._rows), _cols(other._cols) {
  _matrix = new double[_rows * _cols];
  std::memcpy(_matrix, other._matrix,
              other._rows * other._cols * sizeof(double));
}

// Конструктор переноса
S21Matrix::S21Matrix(S21Matrix&& other) {
  _rows = other._rows;
  _cols = other._cols;
  _matrix = other._matrix;
  other._rows = 0;
  other._cols = 0;
  other._matrix = NULL;
}

// Деструктор
S21Matrix::~S21Matrix() {}
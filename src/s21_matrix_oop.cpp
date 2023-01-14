#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _matrix = new double[_rows * _cols]();
}

S21Matrix::S21Matrix(int rows, int cols)
    : _rows(rows),
      _cols(cols),
      _matrix(nullptr) {  // инициализация по умолчанию
  _matrix = new double[_rows * _cols]();
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : _rows(other._rows), _cols(other._cols) {
  _matrix = new double[_rows * _cols]();
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
  other._matrix = nullptr;
}

// Деструктор
S21Matrix::~S21Matrix() {
  if (_matrix) {
    delete[] _matrix;
    _rows = 0;
    _cols = 0;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    return false;
  } else {
    for (int i = 0; i < _cols * _rows; i++) {
      if (_matrix[i] != other._matrix[i]) {
        return false;
      }
    }
  }
  return true;
}

// создать функцию setIndex

int S21Matrix::getIndex(int x, int y) { return y * _cols + x; }

void S21Matrix::setValue(int x, int y, double value) {
  _matrix[getIndex(x, y)] = value;
}

int S21Matrix::getRows() { return _rows; }
int S21Matrix::getCols() { return _cols; }
double* S21Matrix::getMatrix() { return _matrix; }

void S21Matrix::printm() {
  for (int i = 0; i < this->getRows() * this->getCols(); i++) {
    std::cout << this->getMatrix()[i] << ' ';
  }
}

// bool S21Matrix::SumMatrix(const S21Matrix& other) {}

int main() {
  S21Matrix other(3, 3);
  S21Matrix my(3, 3);
  // int index = my.getIndex(4, 2);

  // other.setValue(0, 0, 3.4553);

  // std::cout << index;

  other.setValue(0, 0, 3.4553);

  my.setValue(0, 0, 3.4553);
  my.setValue(0, 1, 5);

  S21Matrix aboba(my);

  other.printm();
  std::cout << "\n";
  my.printm();

  bool a = my.EqMatrix(other);
  std::cout << "\n";
  std::cout << a;
}
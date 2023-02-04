#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  _rows = 3;
  _cols = 3;
  _matrix = new double*[_rows]();
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols]();
  }
}

S21Matrix::S21Matrix(int rows, int cols)
    : _rows(rows), _cols(cols) {  // инициализация по умолчанию
  if (rows > 0 && cols > 0) {
    _matrix = new double*[_rows]();
    for (int i = 0; i < _rows; i++) {
      _matrix[i] = new double[_cols]();
    }
  } else {
    throw std::out_of_range("Incorrect input");
  }
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : _rows(other._rows), _cols(other._cols) {
  for (int i = 0; i < _rows; ++i)
    for (int j = 0; j < _cols; ++j) _matrix[i][j] = other._matrix[i][j];
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
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
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

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::exception();
  } else {
    for (int i = 0; i < _rows; i++) {
      for (int y = 0; y < _cols; y++) {
        _matrix[i][y] += other._matrix[i][y];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::exception();
  } else {
    for (int i = 0; i < _rows; i++) {
      for (int y = 0; y < _cols; y++) {
        _matrix[i][y] -= other._matrix[i][y];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < _rows; i++) {
    for (int y = 0; y < _cols; y++) {
      _matrix[i][y] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (_cols != other._rows) {
    throw std::exception();
  }
  S21Matrix matrix_mul(_rows, other._cols);
  for (int i = 0; i < matrix_mul._rows; i++) {
    for (int y = 0; y < matrix_mul._cols; y++) {
      for (int k = 0; k < _cols; k++) {
        matrix_mul._matrix[i][y] = matrix_mul._matrix[i][y] +
                                   (this->_matrix[i][k] * other._matrix[k][y]);
      }
    }
  }
  *this = std::move(matrix_mul);
}

void S21Matrix::setValue(int x, int y, double value) { _matrix[x][y] = value; }

int S21Matrix::getRows() { return _rows; }
int S21Matrix::getCols() { return _cols; }
double** S21Matrix::getMatrix() { return _matrix; }

void S21Matrix::printm() {
  for (int i = 0; i < this->getRows(); i++) {
    for (int y = 0; y < this->getCols(); y++) {
      if (y == 0) {
        std::cout << '\n';
      }
      std::cout << this->getMatrix()[i][y] << ' ';
    }
  }
}

int main() {
  S21Matrix matrix;
  // S21Matrix other(3, 3);
  S21Matrix my(4, 4);

  my.setValue(0, 0, 3);

  my.setValue(3, 2, 5);

  // std::cout << index;

  // other.setValue(0, 0, 1);
  // other.setValue(0, 1, 2);

  // my.setValue(0, 0, 3);
  // my.setValue(0, 1, 5);

  // my.printm();
  // std::cout << "\n";
  // other.printm();

  // // bool a = my.EqMatrix(other);
  // std::cout << "\n";
  // // std::cout << a;

  // // std::cout << "\n";
  // // my.SumMatrix(other);
  // // my.printm();

  // std::cout << "\n";
  // // my.SubMatrix(other);
  // // my.printm();

  // my.MulNumber(2);
  my.printm();
}
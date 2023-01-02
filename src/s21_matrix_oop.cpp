#include "s21_matrix_oop.h"

void main () {
    
}

class S21Matrix {
    private:
        // Attributes
        int rows_;
        int cols_;
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor
        S21Matrix(int rows, int cols) {
            rows_ = rows;
            cols_ = cols;
        }
        S21Matrix(const S21Matrix& other) {

        }
        
        S21Matrix(S21Matrix&& other) {

        }
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

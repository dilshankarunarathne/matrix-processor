#include <iostream>
#include <algorithm>

class Matrix {
  private:
    int n;
    int **matrix;

  public:
    // Default constructor
    Matrix() : n(0), matrix(nullptr) {}

    // Overloaded constructor with dimensions
    Matrix(int n) : n(n) {
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) : n(other.n) {
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            std::copy(other.matrix[i], other.matrix[i] + n, matrix[i]);
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Overloaded assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            if (n != other.n) {
                for (int i = 0; i < n; i++) {
                    delete[] matrix[i];
                }
                delete[] matrix;

                n = other.n;
                matrix = new int*[n];
                for (int i = 0; i < n; i++) {
                    matrix[i] = new int[n];
                }
            }

            for (int i = 0; i < n; i++) {
                std::copy(other.matrix[i], other.matrix[i] + n, matrix[i]);
            }
        }
        return *this;
    }

    // Overloaded addition operator for matrix addition
    Matrix operator+(const Matrix& other) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    // Overloaded subtraction operator for matrix subtraction
    Matrix operator-(const Matrix& other) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    // Overloaded multiplication operator for matrix multiplication
    Matrix operator*(const Matrix& other) {
        Matrix result(n);
        
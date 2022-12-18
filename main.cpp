#include <iostream>

class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int[rows * cols];
    }

    ~Matrix() {
        delete[] data;
    }

    int& operator()(int row, int col) {
        return data[row * cols + col];
    }

    int operator()(int row, int col) const {
        return data[row * cols + col];
    }
};

int main() {

    return 0;
}


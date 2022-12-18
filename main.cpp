#include <iostream>

int main() {

    return 0;
}

class Matrix {
    private:
        int rows;
        int cols;
        int **matrix;
    public:
        Matrix(int rows, int cols);
        ~Matrix();
        void set(int row, int col, int value);
        int get(int row, int col);
        void print();

    /**
     * adds two Matrices and returns the result
     */
    Matrix add(Matrix m, Matrix n);
};

Matrix Matrix::add(Matrix m, Matrix n) {
    Matrix result(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.set(i, j, m.get(i, j) + n.get(i, j));
        }
    }
    return result;
}

#include <iostream>

/**
 * @brief Implements a three-by-three matrix
 * @details This class implements a three-by-three matrix
 *         and provides methods to perform basic matrix
 *         operations.
 */
class Matrix {
public:
    /**
     * @brief Default constructor
     * @details Initializes the matrix to the identity matrix
     */
    Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = 0;
            }
        }
    }

    /**
     * @brief Constructor
     * @param a00 First element of the first row
     * @param a01 Second element of the first row
     * @param a02 Third element of the first row
     * @param a10 First element of the second row
     * @param a11 Second element of the second row
     * @param a12 Third element of the second row
     * @param a20 First element of the third row
     * @param a21 Second element of the third row
     * @param a22 Third element of the third row
     */
    Matrix(int a00, int a01, int a02, int a10, int a11, int a12, int a20, int a21, int a22) {
        m[0][0] = a00;
        m[0][1] = a01;
        m[0][2] = a02;
        m[1][0] = a10;
        m[1][1] = a11;
        m[1][2] = a12;
        m[2][0] = a20;
        m[2][1] = a21;
        m[2][2] = a22;
    }

    /**
     * @brief Copy constructor
     * @param other The matrix to copy
     */
    Matrix(const Matrix& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = other.m[i][j];
            }
        }
    }

    /**
     * @brief Assignment operator
     * @param other The matrix to copy
     * @return A reference to this matrix
     */
    Matrix& operator=(const Matrix& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] =
};

int main() {

    return 0;
}


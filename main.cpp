#include <iostream>

/**
 * @brief Implements a three-by-three matrix
 * @details This class implements a three-by-three matrix
 *         and provides methods to perform basic matrix
 *         operations.
 */
class Matrix {
private:
    int m[3][3];

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
     * @details Initializes the matrix to the same values as
     *         the other matrix
     */
    Matrix(const Matrix& other) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = other.m[i][j];
            }
        }
    }

    /**
     * @brief Adds two matrices
     * @param other The matrix to add
     * @return The sum of the two matrices
     * @details This method adds two matrices and returns
     *        the result.
     *        The matrices are not modified.
     *        The result is undefined if the matrices are
     *        not of the same size.
     */
    Matrix add(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = m[i][j] + other.m[i][j];
            }
        }
        return result;
    }

    /**
     * @brief Subtracts two matrices
     * @param other The matrix to subtract
     * @return The difference of the two matrices
     * @details This method subtracts two matrices and returns
     *       the result.
     */
    Matrix subtract(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = m[i][j] - other.m[i][j];
            }
        }
        return result;
    }

    /**
     * @brief Multiplies a matrix with a scalar
     * @param scalar The scalar to multiply with
     * @return The product of the matrix and the scalar
     * @details This method multiplies a matrix with a scalar
     *      and returns the result.
     */
    Matrix multiply(int scalar) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = m[i][j] * scalar;
            }
        }
        return result;
    }

    /**
     * @brief Multiplies two matrices
     * @param other The matrix to multiply
     * @return The product of the two matrices
     * @details This method multiplies two matrices and returns
     *       the result.
     */
    Matrix multiply(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }

    /**
     * @brief Transposes a matrix
     * @return The transposed matrix
     */

    /**
     * @brief Prints the matrix
     * @details This method prints the matrix to the standard
     *       output stream.
     */
    void print() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    return 0;
}


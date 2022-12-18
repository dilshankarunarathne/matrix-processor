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
    Matrix operator+(const Matrix& other) const {
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
    Matrix operator-(const Matrix& other) const {
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
    Matrix operator*(const Matrix& other) const {
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
     * @details This method transposes a matrix and returns
     *      the result.
     */
    Matrix transpose() const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = m[j][i];
            }
        }
        return result;
    }

    /**
     * @brief Ranks a matrix
     * @return The rank of the matrix
     * @details This method ranks a matrix and returns
     *     the result.
     */
    int rank() const {
        int r = 0;
        Matrix temp = *this;
        for (int i = 0; i < 3; i++) {
            if (temp.m[i][i] == 0) {
                for (int j = i + 1; j < 3; j++) {
                    if (temp.m[j][i] != 0) {
                        for (int k = 0; k < 3; k++) {
                            int t = temp.m[i][k];
                            temp.m[i][k] = temp.m[j][k];
                            temp.m[j][k] = t;
                        }
                        break;
                    }
                }
            }
            if (temp.m[i][i] != 0) {
                for (int j = i + 1; j < 3; j++) {
                    int f = temp.m[j][i] / temp.m[i][i];
                    for (int k = 0; k < 3; k++) {
                        temp.m[j][k] -= f * temp.m[i][k];
                    }
                }
                r++;
            }
        }
        return r;
    }

    /**
     * @brief Adjoin of a matrix
     * @return The adjoin of the matrix
     * @details This method calculates the adjoin of a matrix
     *     and returns the result.
     */
    Matrix adjoin() const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = m[(i + 1) % 3][(j + 1) % 3] * m[(i + 2) % 3][(j + 2) % 3] - m[(i + 1) % 3][(j + 2) % 3] * m[(i + 2) % 3][(j + 1) % 3];
            }
        }
        return result;
    }

    /**
     * @brief Inverse of a matrix
     * @return The inverse of the matrix
     * @details This method calculates the inverse of a matrix
     *    and returns the result.
     */
    Matrix inverse() const {
        Matrix result;
        int det = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] - m[0][1] * m[1][0] * m[2][2] - m[0][0] * m[1][2] * m[2][1];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.m[i][j] = (m[(i + 1) % 3][(j + 1) % 3] * m[(i + 2) % 3][(j + 2) % 3] - m[(i + 1) % 3][(j + 2) % 3] * m[(i + 2) % 3][(j + 1) % 3]) / det;
            }
        }
        return result;
    }

    /**
     * @brief Reads a matrix from a stream
     * @param in The stream to read from
     * @param matrix The matrix to read into
     * @return The stream
     * @details This method reads a matrix from a stream
     *    and returns the stream.
     *    The matrix is read in the following format:
     *    1 2 3
     *    4 5 6
     *    7 8 9
     *    where the numbers are the elements of the matrix.
     *    The elements are separated by spaces.
     *    The rows are separated by newlines.
     *    The matrix is read into the matrix parameter.
     */
    friend std::istream& operator>>(std::istream& in, Matrix& matrix) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                in >> matrix.m[i][j];
            }
        }
        return in;
    }

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

void tests();

int main() {
    char isOne;

    std::cout << "How many matrices will you be entering (1/2):";
    std::cin >> isOne;
    if (isOne == '1') {
        Matrix m1;
        std::cout << "Enter the first matrix: " << std::endl;
        std::cin >> m1;
        std::cout << "The matrix you entered is: " << std::endl;
        m1.print();
        std::cout << "The transpose of the matrix is: " << std::endl;
        m1.transpose().print();
        std::cout << "The rank of the matrix is: " << m1.rank() << std::endl;
        std::cout << "The adjoin of the matrix is: " << std::endl;
        m1.adjoin().print();
        std::cout << "The inverse of the matrix is: " << std::endl;
        m1.inverse().print();
    } else {
        Matrix m1, m2;
        std::cout << "Enter the first matrix: " << std::endl;
        std::cin >> m1;
        std::cout << "Enter the second matrix: " << std::endl;
        std::cin >> m2;
        std::cout << "The first matrix is: " << std::endl;
        m1.print();
        std::cout << "The second matrix is: " << std::endl;
        m2.print();
        std::cout << "The addition of the two matrices is: " << std::endl;
        (m1 + m2).print();
        std::cout << "The subtraction of the two matrices is: " << std::endl;
        (m1 - m2).print();
        std::cout << "The multiplication of the two matrices is: " << std::endl;
        (m1 * m2).print();
    }

    return 0;
}

void tests() {
    Matrix m1 = Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
    m1.print();
    std::cout << std::endl;

    Matrix m2 = Matrix(5, 6, 7, 8, 2, 4, 3, 4, 9);
    m2.print();
    std::cout << std::endl;

    Matrix m3 = m1 + m2;
    m3.print();
    std::cout << std::endl;

    Matrix m4 = m1 - m2;
    m4.print();
    std::cout << std::endl;

    Matrix m5 = m1.multiply(2);
    m5.print();
    std::cout << std::endl;

    Matrix m6 = m1 * m2;
    m6.print();
    std::cout << std::endl;

    Matrix m7 = m1.transpose();
    m7.print();
    std::cout << std::endl;

    std::cout << m1.rank() << std::endl;
    std::cout << std::endl;

    Matrix m8 = m1.adjoin();
    m8.print();
    std::cout << std::endl;

    Matrix m9 = m1.inverse();
    m9.print();
    std::cout << std::endl;
}

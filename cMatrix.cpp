//
// Created by Dilshan Karunarathne on 1/25/2023.
// enables users to enter two matrices of nxn, where n is any positive integer.
// then the program displays the sum, difference, multiplication, transpose matrices of the two matrices.
// object oriented principles are used to implement the program.
//

#include "cMatrix.h"

using namespace std;

// Path: cMatrix.h
// Compare this snippet from cMatrix.h:

// Path: cMatrix.cpp
// Compare this snippet from cMatrix.h:

#include "cMatrix.h"

cMatrix::cMatrix(int n) {
    this->n = n;
    m = new double*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
    }
}

cMatrix::cMatrix(const cMatrix& rhs) {
    n = rhs.n;
    m = new double*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rhs.m[i][j];
        }
    }
}

cMatrix::~cMatrix() {
    for (int i = 0; i < n; i++) {
        delete[] m[i];
    }
    delete[] m;
}

cMatrix& cMatrix::operator=(const cMatrix& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < n; i++) {
            delete[] m[i];
        }
        delete[] m;
        n = rhs.n;
        m = new double*[n];
        for (int i = 0; i < n; i++) {
            m[i] = new double[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = rhs.m[i][j];
            }
        }
    }
    return *this;
}

cMatrix& cMatrix::operator+=(const cMatrix& rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] += rhs.m[i][j];
        }
    }
    return *this;
}

cMatrix& cMatrix::operator-=(const cMatrix& rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] -= rhs.m[i][j];
        }
    }
    return *this;
}

cMatrix& cMatrix::operator*=(const cMatrix& rhs) {
    double** temp = new double*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += m[i][k] * rhs.m[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] m[i];
    }
    delete[] m;
    m = temp;
    return *this;
}

cMatrix& cMatrix::operator*=(const int scalar) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] *= scalar;
        }
    }
    return *this;
}

cMatrix operator+(const cMatrix& m1, const cMatrix& m2) {
    cMatrix temp(m1);
    temp += m2;
    return temp;
}

cMatrix operator-(const cMatrix& m1, const cMatrix& m2) {
    cMatrix temp(m1);
    temp -= m2;
    return temp;
}

cMatrix operator*(const cMatrix& m1, const cMatrix& m2) {
    cMatrix temp(m1);
    temp *= m2;
    return temp;
}

cMatrix operator*(const cMatrix& m, const int scalar) {
    cMatrix temp(m);
    temp *= scalar;
    return temp;
}

cMatrix operator*(const int scalar, const cMatrix& m) {
    cMatrix temp(m);
    temp *= scalar;
    return temp;
}

istream& operator>>(istream& in, cMatrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            in >> matrix.m[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const cMatrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            out << matrix.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

void cMatrix::set(int i, int j, double val) {
    m[i][j] = val;
}

double cMatrix::get(int i, int j) const {
    return m[i][j];
}

int cMatrix::getSize() const {
    return n;
}

cMatrix cMatrix::transpose() const {
    cMatrix temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.m[i][j] = m[j][i];
        }
    }
    return temp;
}

cMatrix cMatrix::adjoin() const {
    cMatrix temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.m[i][j] = pow(-1, i + j) * subMatrix(i, j).determinant();
        }
    }
    return temp;
}

cMatrix cMatrix::inverse() const {
    cMatrix temp(n);
    double det = determinant();
    if (det == 0) {
        cout << "Matrix is not invertible." << endl;
        return temp;
    }
    temp = adjoin().transpose();
    temp *= (1 / det);
    return temp;
}

cMatrix cMatrix::subMatrix(int row, int col) const {
    cMatrix temp(n - 1);
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) {
            continue;
        }
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) {
                continue;
            }
            temp.m[r][c] = m[i][j];
            c++;
        }
        r++;
    }
    return temp;
}

double cMatrix::determinant() const {
    if (n == 1) {
        return m[0][0];
    }
    double det = 0;
    for (int i = 0; i < n; i++) {
        det += pow(-1, i) * m[0][i] * subMatrix(0, i).determinant();
    }
    return det;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    cMatrix m1(n);
    cout << "Enter the elements of the matrix: " << endl;
    cin >> m1;
    cout << "The matrix is: " << endl;
    cout << m1;
    cout << "The transpose of the matrix is: " << endl;
    cout << m1.transpose();
    cout << "The adjoin of the matrix is: " << endl;
    cout << m1.adjoin();
    cout << "The inverse of the matrix is: " << endl;
    cout << m1.inverse();
    cout << "The determinant of the matrix is: " << endl;
    cout << m1.determinant();
    return 0;
}



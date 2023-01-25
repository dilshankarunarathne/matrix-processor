/*
 * write a program that enables user to enter two matrices of dimension nxn, where n is any positive integer. then the program displays the sum, difference, multiplication, transpose matrices of entered matrices. object oriented principles shoul be applied to solve the programming poroblem with the following features.
 * a class to represent nxn matrix
 * appropriate constructions
 * overridden default constructor
 * overloaded constructors
 * copy constructors
 * overloaded operators
 * operators should support chaining
 * garbage collection to handle all temporary objects, enabling proper chaining of overloaded operators, copy constructor.
 * all this is defined in newCMatrix.h
 */

#include "newCMatrix.h"

newCMatrix::newCMatrix(int n) {
    this->n = n;
    m = new double*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
    }
}

newCMatrix::newCMatrix(const newCMatrix &rhs) {
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

newCMatrix::~newCMatrix() {
    for (int i = 0; i < n; i++) {
        delete[] m[i];
    }
    delete[] m;
}

newCMatrix &newCMatrix::operator=(const newCMatrix &rhs) {
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

newCMatrix &newCMatrix::operator+=(const newCMatrix &rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] += rhs.m[i][j];
        }
    }
    return *this;
}

newCMatrix &newCMatrix::operator-=(const newCMatrix &rhs) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] -= rhs.m[i][j];
        }
    }
    return *this;
}

newCMatrix &newCMatrix::operator*=(const newCMatrix &rhs) {
    newCMatrix temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp.m[i][j] += m[i][k] * rhs.m[k][j];
            }
        }
    }
    *this = temp;
    return *this;
}

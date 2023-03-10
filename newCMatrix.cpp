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

newCMatrix &newCMatrix::operator*=(int scalar) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] *= scalar;
        }
    }
    return *this;
}

/*
newCMatrix &newCMatrix::operator/=(int scalar) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] /= scalar;
        }
    }
    return *this;
}

newCMatrix newCMatrix::operator+(const newCMatrix &rhs) const {
    newCMatrix temp(*this);
    temp += rhs;
    return temp;
}

newCMatrix newCMatrix::operator-(const newCMatrix &rhs) const {
    newCMatrix temp(*this);
    temp -= rhs;
    return temp;
}

newCMatrix newCMatrix::operator*(const newCMatrix &rhs) const {
    newCMatrix temp(*this);
    temp *= rhs;
    return temp;
}

newCMatrix newCMatrix::operator*(int scalar) const {
    newCMatrix temp(*this);
    temp *= scalar;
    return temp;
}

newCMatrix newCMatrix::operator/(int scalar) const {
    newCMatrix temp(*this);
    temp /= scalar;
    return temp;
}

newCMatrix newCMatrix::operator-() const {
    newCMatrix temp(*this);
    temp *= -1;
    return temp;
}

newCMatrix newCMatrix::operator+() const {
    return *this;
}

newCMatrix newCMatrix::operator++() {
    *this += 1;
    return *this;
}

newCMatrix newCMatrix::operator++(int) {
    newCMatrix temp(*this);
    *this += 1;
    return temp;
}

newCMatrix newCMatrix::operator--() {
    *this -= 1;
    return *this;
}

newCMatrix newCMatrix::operator--(int) {
    newCMatrix temp(*this);
    *this -= 1;
    return temp;
}

bool newCMatrix::operator==(const newCMatrix &rhs) const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != rhs.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}
*/

std::ostream &operator<<(std::ostream &os, const newCMatrix &rhs) {
    for (int i = 0; i < rhs.n; i++) {
        for (int j = 0; j < rhs.n; j++) {
            os << rhs.m[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, newCMatrix &rhs) {
    for (int i = 0; i < rhs.n; i++) {
        for (int j = 0; j < rhs.n; j++) {
            is >> rhs.m[i][j];
        }
    }
    return is;
}

newCMatrix operator+(const newCMatrix &m1, const newCMatrix &m2) {
    newCMatrix temp(m1);
    temp += m2;
    return temp;
}

newCMatrix operator-(const newCMatrix &m1, const newCMatrix &m2) {
    newCMatrix temp(m1);
    temp -= m2;
    return temp;
}

newCMatrix operator*(const newCMatrix &m1, const newCMatrix &m2) {
    newCMatrix temp(m1);
    temp *= m2;
    return temp;
}

newCMatrix operator*(const newCMatrix &m, const int scalar) {
    newCMatrix temp(m);
    temp *= scalar;
    return temp;
}

newCMatrix operator*(const int scalar, const newCMatrix &m) {
    newCMatrix temp(m);
    temp *= scalar;
    return temp;
}

newCMatrix newCMatrix::transpose() const {
    newCMatrix temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.m[i][j] = m[j][i];
        }
    }
    return temp;
}

newCMatrix newCMatrix::adjoin() const {
    newCMatrix temp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.m[i][j] = m[j][i];
        }
    }
    return temp;
}

newCMatrix newCMatrix::inverse() const {
    newCMatrix temp(n);
    return temp;
}

int main() {
    return 0;
}


#ifndef MATRIX_PROCESSOR_CMATRIX_H
#define MATRIX_PROCESSOR_CMATRIX_H

#include <iostream>
#include <iomanip>

using namespace std;

class cMatrix {
private:
    int n;
    double** m;
public:
    cMatrix(int n);
    cMatrix(const cMatrix& rhs);
    ~cMatrix();

    cMatrix& operator=(const cMatrix& rhs);
    cMatrix& operator+=(const cMatrix& rhs);
    cMatrix& operator-=(const cMatrix& rhs);
    cMatrix& operator*=(const cMatrix& rhs);
    cMatrix& operator*=(const int scalar);

    friend cMatrix operator+(const cMatrix& m1, const cMatrix& m2);
    friend cMatrix operator-(const cMatrix& m1, const cMatrix& m2);
    friend cMatrix operator*(const cMatrix& m1, const cMatrix& m2);
    friend cMatrix operator*(const cMatrix& m, const int scalar);
    friend cMatrix operator*(const int scalar, const cMatrix& m);

    friend istream& operator>>(istream& in, cMatrix& matrix);
    friend ostream& operator<<(ostream& out, const cMatrix& matrix);

    void set(int i, int j, double val);
    double get(int i, int j) const;
    int getSize() const;
    cMatrix transpose() const;
    cMatrix adjoin() const;
    cMatrix inverse() const;
    int rank() const;

    double determinant() const;

    cMatrix subMatrix(int row, int col) const;

    double pow(int i, int i1) const;
};

#endif //MATRIX_PROCESSOR_CMATRIX_H

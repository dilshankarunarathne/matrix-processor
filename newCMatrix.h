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
 */

#ifndef MATRIX_PROCESSOR_NEWCMATRIX_H
#define MATRIX_PROCESSOR_NEWCMATRIX_H


class newCMatrix {
private:
    int n;
    double** m;
public:
    newCMatrix(int n);
    newCMatrix(const newCMatrix& rhs);
    ~newCMatrix();

    newCMatrix& operator=(const newCMatrix& rhs);
    newCMatrix& operator+=(const newCMatrix& rhs);
    newCMatrix& operator-=(const newCMatrix& rhs);
    newCMatrix& operator*=(const newCMatrix& rhs);
    newCMatrix& operator*=(const int scalar);

    friend newCMatrix operator+(const newCMatrix& m1, const newCMatrix& m2);
    friend newCMatrix operator-(const newCMatrix& m1, const newCMatrix& m2);
    friend newCMatrix operator*(const newCMatrix& m1, const newCMatrix& m2);
    friend newCMatrix operator*(const newCMatrix& m, const int scalar);
    friend newCMatrix operator*(const int scalar, const newCMatrix& m);

    friend istream& operator>>(istream& in, newCMatrix& matrix);
    friend ostream& operator<<(ostream& out, const newCMatrix& matrix);

    void set(int i, int j, double val);
    double get(int i, int j) const;
    int getSize() const;
    newCMatrix transpose() const;
    newCMatrix adjoin() const;
    newCMatrix inverse() const;
    int rank() const;

    double determinant() const;

    newCMatrix subMatrix(int row, int col) const;

    double pow(int i, int i1) const;
};


#endif //MATRIX_PROCESSOR_NEWCMATRIX_H

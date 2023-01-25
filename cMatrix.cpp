//
// Created by Dilshan Karunarathne on 1/25/2023.
// enables users to enter two matrices of nxn, where n is any positive integer.
// then the program displays the sum, difference, multiplication, transpose matrices of the two matrices.
// object oriented principles are used to implement the program.
//

#include "cMatrix.h"

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    cMatrix m1(n);
    cMatrix m2(n);
    cout << "Enter the first matrix: " << endl;
    cin >> m1;
    cout << "Enter the second matrix: " << endl;
    cin >> m2;
    cout << "The first matrix is: " << endl;
    cout << m1;
    cout << "The second matrix is: " << endl;
    cout << m2;
    cout << "The sum of the two matrices is: " << endl;
    cout << m1 + m2;
    cout << "The difference of the two matrices is: " << endl;
    cout << m1 - m2;
    cout << "The product of the two matrices is: " << endl;
    cout << m1 * m2;
    cout << "The transpose of the first matrix is: " << endl;
    cout << m1.transpose();
    cout << "The transpose of the second matrix is: " << endl;
    cout << m2.transpose();
    return 0;
}


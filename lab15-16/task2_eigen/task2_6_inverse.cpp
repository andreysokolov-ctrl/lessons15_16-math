#include <iostream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {
    setlocale(LC_ALL, "");

    MatrixXd A(3, 3);
    A << 1, 2, 3,
         0, 1, 4,
         5, 6, 0;

    cout << "A =\n" << A << endl;

    cout << "\ndet(A) = " << A.determinant() << endl;

    if (A.determinant() != 0) {
        MatrixXd Ainv = A.inverse();
        cout << "\nA^{-1} =\n" << Ainv << endl;

        MatrixXd I = A * Ainv;
        cout << "\nA * A^{-1} =\n" << I << endl;
    }
    else {
        cout << "Матрица необратима!" << endl;
    }

    return 0;
}

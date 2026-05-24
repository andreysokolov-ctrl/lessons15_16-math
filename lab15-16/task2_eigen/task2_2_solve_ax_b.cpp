#include <iostream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

int main() {
    setlocale(LC_ALL, "");

    MatrixXd A(3, 3);
    VectorXd B(3);

    A <<  2,  1, -1,
         -3, -1,  2,
         -2,  1,  2;

    B << 8, -11, -3;

    cout << "A =\n" << A << endl;
    cout << "\nB = " << B.transpose() << endl;

    VectorXd x = A.colPivHouseholderQr().solve(B);
    cout << "\nРешение x = " << x.transpose() << endl;

    double residual = (A * x - B).norm();
    cout << "Невязка ||Ax - B|| = " << residual << endl;

    return 0;
}

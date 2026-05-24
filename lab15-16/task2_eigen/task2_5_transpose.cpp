#include <iostream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {
    setlocale(LC_ALL, "");

    MatrixXd A(3, 4);
    A <<  1,  2,  3,  4,
          5,  6,  7,  8,
          9, 10, 11, 12;

    cout << "A (3×4) =\n" << A << endl;

    MatrixXd AT = A.transpose();
    cout << "\nA^T (4×3) =\n" << AT << endl;

    // Проверка: A^T * A должна быть симметричной
    MatrixXd ATA = AT * A;
    cout << "\nA^T * A (4×4) =\n" << ATA << endl;
    cout << "Симметрична: " << (ATA.isApprox(ATA.transpose()) ? "да" : "нет") << endl;

    // Для квадратных матриц — transposeInPlace()
    MatrixXd B(3, 3);
    B << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << "\nB до transposeInPlace:\n" << B << endl;
    B.transposeInPlace();
    cout << "B после:\n" << B << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;

int main() {
    setlocale(LC_ALL, "");

    // Норма вектора
    VectorXd v(5);
    v << 1.0, -2.0, 3.0, -4.0, 5.0;

    double normEigen = v.norm();

    double normManual = 0.0;
    for (int i = 0; i < v.size(); i++)
        normManual += v(i) * v(i);
    normManual = sqrt(normManual);

    cout << "Вектор v = " << v.transpose() << endl;
    cout << "Норма (Eigen)  : " << normEigen  << endl;
    cout << "Норма (ручная) : " << normManual << endl;

    // Норма Фробениуса матрицы
    MatrixXd M(3, 3);
    M << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    double normF = M.norm();

    double normFManual = 0.0;
    for (int i = 0; i < M.rows(); i++)
        for (int j = 0; j < M.cols(); j++)
            normFManual += M(i, j) * M(i, j);
    normFManual = sqrt(normFManual);

    cout << "\nМатрица M =\n" << M << endl;
    cout << "Норма Фробениуса (Eigen)  : " << normF       << endl;
    cout << "Норма Фробениуса (ручная) : " << normFManual << endl;

    return 0;
}

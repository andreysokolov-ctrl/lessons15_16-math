#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

vector<vector<double>> multiplyManual(const vector<vector<double>>& A,
                                      const vector<vector<double>>& B, int n)
{
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

int main() {
    setlocale(LC_ALL, "");

    const int N = 500;

    mt19937 gen(42);
    uniform_real_distribution<double> dist(0.0, 100.0);

    vector<vector<double>> A(N, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(N));
    MatrixXd EA(N, N), EB(N, N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            double a = dist(gen), b = dist(gen);
            A[i][j] = a;   B[i][j] = b;
            EA(i, j) = a;  EB(i, j) = b;
        }

    // Ручной алгоритм
    auto t0 = chrono::high_resolution_clock::now();
    auto C = multiplyManual(A, B, N);
    auto t1 = chrono::high_resolution_clock::now();
    chrono::duration<double> tManual = t1 - t0;

    // Eigen
    auto t2 = chrono::high_resolution_clock::now();
    MatrixXd EC = EA * EB;
    auto t3 = chrono::high_resolution_clock::now();
    chrono::duration<double> tEigen = t3 - t2;

    cout << "Ручной алгоритм : " << tManual.count() << " с" << endl;
    cout << "Eigen           : " << tEigen.count()  << " с" << endl;
    cout << "Ускорение       : " << tManual.count() / tEigen.count() << "x" << endl;

    cout << "\nПроверка C[0][0]: ручной=" << C[0][0]
         << "  Eigen=" << EC(0, 0) << endl;

    size_t bytes = 3ULL * N * N * sizeof(double);
    cout << "Память под 3 матрицы: " << bytes / 1024 / 1024 << " МБ" << endl;
    cout << "(детальная картина — в профилировщике VS)" << endl;

    return 0;
}

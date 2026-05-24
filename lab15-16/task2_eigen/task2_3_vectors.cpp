#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>
#include <Eigen/Dense>

using namespace std;
using Eigen::VectorXd;

int main() {
    setlocale(LC_ALL, "");

    const int N = 1000;

    mt19937 gen(42);
    uniform_real_distribution<double> dist(-10.0, 10.0);

    vector<double> xv(N), yv(N);
    VectorXd xE(N), yE(N);

    for (int i = 0; i < N; i++) {
        double xi = dist(gen), yi = dist(gen);
        xv[i] = xi;  yv[i] = yi;
        xE(i) = xi;  yE(i) = yi;
    }

    // Ручной подсчёт
    auto t0 = chrono::high_resolution_clock::now();

    double dotManual = 0.0;
    for (int i = 0; i < N; i++)
        dotManual += xv[i] * yv[i];

    double normManual = 0.0;
    for (int i = 0; i < N; i++)
        normManual += xv[i] * xv[i];
    normManual = sqrt(normManual);

    auto t1 = chrono::high_resolution_clock::now();

    // Eigen
    auto t2 = chrono::high_resolution_clock::now();

    double dotEigen  = xE.dot(yE);
    double normEigen = xE.norm();

    auto t3 = chrono::high_resolution_clock::now();

    chrono::duration<double> tManual = t1 - t0;
    chrono::duration<double> tEigen  = t3 - t2;

    cout << "Скалярное произведение (ручной): " << dotManual << endl;
    cout << "Скалярное произведение (Eigen) : " << dotEigen  << endl;

    cout << "\nЕвклидова норма x (ручной): " << normManual << endl;
    cout << "Евклидова норма x (Eigen) : " << normEigen  << endl;

    cout << "\nВремя ручного цикла : " << tManual.count() * 1e6 << " мкс" << endl;
    cout << "Время Eigen         : " << tEigen.count()  * 1e6 << " мкс" << endl;

    return 0;
}

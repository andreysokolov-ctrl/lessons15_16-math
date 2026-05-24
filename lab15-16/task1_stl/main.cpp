#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> sortVector(vector<int> v) {
    sort(v.begin(), v.end());
    return v;
}

vector<int> reverseVector(vector<int> v) {
    reverse(v.begin(), v.end());
    return v;
}

int sum(vector<int> arr, int n) {
    return accumulate(arr.begin(), arr.begin() + n, 0);
}

int findFrequency(vector<int> arr, int x) {
    return count(arr.begin(), arr.end(), x);
}

void printVector(const vector<int>& v) {
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");

    vector<int> arr = {5, 3, 8, 1, 9, 2, 7, 4, 6, 3, 3, 10};

    cout << "Исходный вектор: ";
    printVector(arr);

    cout << "После сортировки: ";
    printVector(sortVector(arr));

    cout << "В обратном порядке: ";
    printVector(reverseVector(sortVector(arr)));

    cout << "Сумма элементов: " << sum(arr, arr.size()) << endl;

    int x = 3;
    cout << "Частота числа " << x << ": " << findFrequency(arr, x) << endl;

    return 0;
}

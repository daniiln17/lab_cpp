#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

// Формула 1: x^2 - x^2 + x*4 - x*5 + x + x
double formula1(double x, int iterations) {
    volatile double result = 0.0;
    for (int i = 0; i < iterations; i++) {
        result = pow(x, 2) - pow(x, 2) + x * 4 - x * 5 + x + x;
    }
    return result;
}

// Формула 2: x + x
double formula2(double x, int iterations) {
    volatile double result = 0.0;
    for (int i = 0; i < iterations; i++) {
        result = x + x;
    }
    return result;
}

// Формула 3: результат1 + результат2 - результат1
double formula3(double res1, double res2) {
    return res1 + res2 - res1;
}

int main() {
    double x = 2.0;
    int iterations[] = {10000, 10000000};

    cout << "=== ПОСЛЕДОВАТЕЛЬНЫЕ ВЫЧИСЛЕНИЯ ===" << endl;

    for (int n : iterations) {
        cout << "\nИтераций: " << n << endl;

        // Шаг 1: формула 1
        auto start1 = high_resolution_clock::now();
        double res1 = formula1(x, n);
        auto end1 = high_resolution_clock::now();
        double time1 = duration<double>(end1 - start1).count();

        // Шаг 2: формула 2
        auto start2 = high_resolution_clock::now();
        double res2 = formula2(x, n);
        auto end2 = high_resolution_clock::now();
        double time2 = duration<double>(end2 - start2).count();

        // Шаг 3: формула 3
        auto start3 = high_resolution_clock::now();
        double res3 = formula3(res1, res2);
        auto end3 = high_resolution_clock::now();
        double time3 = duration<double>(end3 - start3).count();

        // Общее время
        double totalTime = time1 + time2 + time3;

        cout << "  Формула 1: " << time1 << " сек" << endl;
        cout << "  Формула 2: " << time2 << " сек" << endl;
        cout << "  Формула 3: " << time3 << " сек" << endl;
        cout << "  ИТОГО:     " << totalTime << " сек" << endl;
    }

    return 0;
}

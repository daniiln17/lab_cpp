#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>

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

// Функция-обёртка для потока
void threadFormula1(double x, int iterations, double* result) {
    *result = formula1(x, iterations);
}

void threadFormula2(double x, int iterations, double* result) {
    *result = formula2(x, iterations);
}

int main() {
    double x = 2.0;
    int iterations[] = {10000, 10000000};

    cout << "=== ПАРАЛЛЕЛЬНЫЕ ВЫЧИСЛЕНИЯ (ПОТОКИ) ===" << endl;

    for (int n : iterations) {
        cout << "\nИтераций: " << n << endl;

        double res1 = 0.0, res2 = 0.0, res3 = 0.0;

        // Засекаем общее время
        auto start = high_resolution_clock::now();

        // Запускаем потоки для формул 1 и 2 (параллельно!)
        thread t1(threadFormula1, x, n, &res1);
        thread t2(threadFormula2, x, n, &res2);

        // Ждём завершения потоков
        t1.join();
        t2.join();

        // Формула 3 выполняется последовательно (зависит от res1 и res2)
        auto start3 = high_resolution_clock::now();
        res3 = formula3(res1, res2);
        auto end3 = high_resolution_clock::now();

        auto end = high_resolution_clock::now();
        double totalTime = duration<double>(end - start).count();
        double time3 = duration<double>(end3 - start3).count();

        cout << "  Формула 1 (поток): " << "выполнена" << endl;
        cout << "  Формула 2 (поток): " << "выполнена" << endl;
        cout << "  Формула 3:         " << time3 << " сек" << endl;
        cout << "  ИТОГО:             " << totalTime << " сек" << endl;
    }

    return 0;
}

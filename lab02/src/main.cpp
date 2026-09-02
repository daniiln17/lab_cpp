#include <iostream>
#include <chrono>
#include <cmath>
#include <limits>

using namespace std;
using namespace chrono;

// Функция для вычисления выражения: x^2 - x^2 + x*4 - x*5 + x + x
double calculate(double x) {
    return pow(x, 2) - pow(x, 2) + x * 4 - x * 5 + x + x;
}

int main() {
    int n;

    while (true) {
        cout << "Введите количество итераций (или букву для выхода): ";

        // Проверка на ввод числа
        if (!(cin >> n)) {
            cout << "Введено не число. Завершение программы." << endl;
            break;
        }

        if (n <= 0) {
            cout << "Введите положительное число!" << endl;
            continue;
        }

        // Засекаем время СТАРТ
        auto start = high_resolution_clock::now();

        // Цикл на n итераций
        volatile double result = 0; // volatile чтобы компилятор не вырезал вычисления
        for (int i = 0; i < n; i++) {
            result = calculate(2.0); // x = 2 (можно подставить любое число)
        }

        // Засекаем время СТОП
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();

        // Вывод результата
        cout << "Выполнено итераций: " << n << endl;
        cout << "Время выполнения: " << duration << " мс" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}

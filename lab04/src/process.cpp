#include <iostream>
#include <chrono>
#include <cmath>
#include <unistd.h>
#include <sys/wait.h>

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

    cout << "=== ПАРАЛЛЕЛЬНЫЕ ВЫЧИСЛЕНИЯ (ПРОЦЕССЫ) ===" << endl;

    for (int n : iterations) {
        cout << "\nИтераций: " << n << endl;

        int pipe1[2], pipe2[2];
        pipe(pipe1); // для передачи res1
        pipe(pipe2); // для передачи res2

        auto start = high_resolution_clock::now();

        pid_t pid1 = fork();
        if (pid1 == 0) {
            // Дочерний процесс 1: вычисляет формулу 1
            double res = formula1(x, n);
            write(pipe1[1], &res, sizeof(res));
            exit(0);
        }

        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Дочерний процесс 2: вычисляет формулу 2
            double res = formula2(x, n);
            write(pipe2[1], &res, sizeof(res));
            exit(0);
        }

        // Родительский процесс: ждём завершения дочерних
        wait(NULL);
        wait(NULL);

        // Читаем результаты из пайпов
        double res1, res2;
        read(pipe1[0], &res1, sizeof(res1));
        read(pipe2[0], &res2, sizeof(res2));

        // Формула 3
        auto start3 = high_resolution_clock::now();
        double res3 = formula3(res1, res2);
        auto end3 = high_resolution_clock::now();

        auto end = high_resolution_clock::now();
        double totalTime = duration<double>(end - start).count();
        double time3 = duration<double>(end3 - start3).count();

        cout << "  Формула 1 (процесс): " << "выполнена" << endl;
        cout << "  Формула 2 (процесс): " << "выполнена" << endl;
        cout << "  Формула 3:           " << time3 << " сек" << endl;
        cout << "  ИТОГО:               " << totalTime << " сек" << endl;

        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
    }

    return 0;
}


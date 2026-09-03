#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Функция сложения 
double add(double a, double b) {
    return a + b;
}

// Функция вычитания
double subtract(double a, double b) {
    return a - b;
}

// Функция умножения 
double multiply(double a, double b) {
    double result = 0;
    bool negative = false;

    // Обработка отрицательных чисел
    if (b < 0) {
        b = -b;
        negative = true;
    }

    for (int i = 0; i < (int)b; i++) {
        result = result + a;
    }

    if (negative) {
        result = -result;
    }

    return result;
}

double power(double base, int exponent) {
    double result = 1.0;
    int absExponent = exponent;

    // Если степень отрицательная — работаем с модулем
    if (exponent < 0) {
        absExponent = -exponent;
    }

    // Возведение в степень через цикл
    for (int i = 0; i < absExponent; i++) {
        result = result * base;
    }

    // Если степень отрицательная — берём обратное число
    if (exponent < 0) {
        result = 1.0 / result;
    }

    return result;
}

// Основная функция калькулятора
double calculate(double a, double b, char op) {
    switch (op) {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '^':
            return power(a, (int)b);
        default:
            cerr << "Ошибка: неизвестный оператор. Используйте +, -, ^" << endl;
            exit(1);
    }
}

// Главная функция
int main(int argc, char* argv[]) {
    // Проверка количества аргументов
    if (argc != 4) {
        cerr << "Использование: " << argv[0] << " <число1> <число2> <оператор>" << endl;
        cerr << "Операторы: +, -, ^" << endl;
        return 1;
    }

    // Парсинг аргументов
    double a = stod(argv[1]);
    double b = stod(argv[2]);
    char op = argv[3][0];

    // Вычисление
    double result = calculate(a, b, op);

    // Вывод результата
    cout << result << endl;

    return 0;
}



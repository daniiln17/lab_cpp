#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Переместить диск " << n << " с " << from << " на " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    if (n <= 0) {
        cout << "Число должно быть > 0" << endl;
        return 1;
    }

    cout << "Последовательность перемещений для " << n << " дисков:\n";
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

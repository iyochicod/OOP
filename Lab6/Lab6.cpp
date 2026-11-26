#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calcPerimeter(int a, int* perimeter) {
    if (perimeter != nullptr) {
        *perimeter = 3 * a;
    }
}

void calcArea(int a, double* area) {
    if (area != nullptr) {
        *area = (static_cast<double>(a) * a * sqrt(3.0)) / 4.0;
    }
}

int main() {
    const int COUNT = 8;
    int sides[COUNT];
    int perimeters[COUNT];
    double areas[COUNT];

    cout << "=== Лабораторна робота №6. Варіант 4 ===" << endl;
    cout << "Обчислення периметра і площі 8 рівносторонніх трикутників." << endl << endl;

    for (int i = 0; i < COUNT; ++i) {
        while (true) {
            cout << "Введіть цілу сторону a для трикутника №" << (i + 1) << ": ";
            cin >> sides[i];

            if (cin.fail() || sides[i] <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Помилка! Довжина сторони має бути цілим додатним числом (a > 0)." << endl;
            } else {
                break;
            }
        }

        calcPerimeter(sides[i], &perimeters[i]);
        calcArea(sides[i], &areas[i]);
    }

    cout << endl << "--- Результати обчислень ---" << endl;
    cout << left << setw(14) << "Трикутник №"
         << setw(14) << "Сторона (a)"
         << setw(16) << "Периметр (P)"
         << setw(16) << "Площа (S)" << endl;
    cout << string(60, '-') << endl;

    cout << fixed << setprecision(4);
    for (int i = 0; i < COUNT; ++i) {
        cout << left << setw(14) << (i + 1)
             << setw(14) << sides[i]
             << setw(16) << perimeters[i]
             << setw(16) << areas[i] << endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Equation {
private:
    double a;
    double b;
    double c;

public:

    Equation() : a(1.0), b(0.0), c(0.0) {}

    Equation(double aVal, double bVal, double cVal) : a(aVal), b(bVal), c(cVal) {}

    void setA(double aVal) { a = aVal; }
    void setB(double bVal) { b = bVal; }
    void setC(double cVal) { c = cVal; }

    void setCoefficients(double aVal, double bVal, double cVal) {
        a = aVal;
        b = bVal;
        c = cVal;
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void printEquation() const {
        cout << "Рівняння: " << a << " * x ";
        if (b >= 0) {
            cout << "+ " << b;
        } else {
            cout << "- " << fabs(b);
        }
        cout << " = " << c << endl;
    }

    void solve() const {
        const double EPS = 1e-9;
        printEquation();

        if (fabs(a) > EPS) {
            double x = (c - b) / a;
            cout << "Розв'язок: єдиний корінь x = " << fixed << setprecision(4) << x << endl;
        } else {
            if (fabs(c - b) <= EPS) {
                cout << "Розв'язок: рівняння має безліч розв'язків (x — будь-яке дійсне число)." << endl;
            } else {
                cout << "Розв'язок: рівняння не має розв'язків." << endl;
            }
        }
    }
};

int main() {
    cout << "=== Лабораторна робота №7. Варіант 4 (Клас Equation) ===" << endl << endl;

    Equation eq1;
    eq1.setA(2.0);
    eq1.setB(5.0);
    eq1.setC(13.0);

    cout << "--- Об'єкт 1 (перевірка get-методів та розв'язування) ---" << endl;
    cout << "Коефіцієнти: a = " << eq1.getA()
         << ", b = " << eq1.getB()
         << ", c = " << eq1.getC() << endl;
    eq1.solve();
    cout << endl;

    Equation eq2(0.0, 4.0, 4.0);
    cout << "--- Об'єкт 2 (вироджений випадок: безліч розв'язків) ---" << endl;
    eq2.solve();
    cout << endl;

    Equation eq3(0.0, 3.0, 9.0);
    cout << "--- Об'єкт 3 (вироджений випадок: немає розв'язків) ---" << endl;
    eq3.solve();
    cout << endl;

    double userA, userB, userC;
    cout << "--- Об'єкт 4 (введення даних користувачем) ---" << endl;
    cout << "Введіть коефіцієнти a, b, c для рівняння ax + b = c: ";
    cin >> userA >> userB >> userC;

    Equation userEq;
    userEq.setCoefficients(userA, userB, userC);
    userEq.solve();

    return 0;
}

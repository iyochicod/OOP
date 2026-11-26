#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CircleAndPoint {
private:
    double radius;
    double centerX;
    double centerY;
    double pointX;
    double pointY;

public:

    CircleAndPoint() : radius(1.0), centerX(0.0), centerY(0.0), pointX(0.0), pointY(0.0) {}

    CircleAndPoint(double r, double cx, double cy, double px, double py)
        : radius(r > 0 ? r : 1.0), centerX(cx), centerY(cy), pointX(px), pointY(py) {}

    void input() {
        while (true) {
            cout << "Введіть радіус кола R (R > 0): ";
            cin >> radius;
            if (!cin.fail() && radius > 0) {
                break;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Помилка! Радіус має бути додатним числом." << endl;
        }

        cout << "Введіть координати центру кола (x0, y0): ";
        cin >> centerX >> centerY;

        cout << "Введіть координати точки (x, y): ";
        cin >> pointX >> pointY;
    }

    double distanceToCenter() const {
        return sqrt(pow(pointX - centerX, 2) + pow(pointY - centerY, 2));
    }

    void checkPointPosition() const {
        const double EPS = 1e-9;
        double dist = distanceToCenter();

        cout << fixed << setprecision(3);
        cout << endl << "--- Параметри об'єкта ---" << endl;
        cout << "Коло: центр O(" << centerX << "; " << centerY << "), радіус R = " << radius << endl;
        cout << "Точка: M(" << pointX << "; " << pointY << ")" << endl;
        cout << "Відстань від точки M до центру O: d = " << dist << endl;

        if (dist < radius - EPS) {
            cout << "Результат: точка M знаходиться ВСЕРЕДИНІ кола (d < R)." << endl;
        } else if (fabs(dist - radius) <= EPS) {
            cout << "Результат: точка M лежить НА МЕЖІ кола (на окружності, d = R)." << endl;
        } else {
            cout << "Результат: точка M знаходиться ЗА МЕЖАМИ кола (d > R)." << endl;
        }
    }
};

int main() {
    cout << "=== Лабораторна робота №8. Варіант 4 (Коло та точка) ===" << endl << endl;

    CircleAndPoint userObj;
    userObj.input();
    userObj.checkPointPosition();

    cout << endl << "=== Додаткові тестові приклади ===" << endl;
    CircleAndPoint onBorder(5.0, 0.0, 0.0, 3.0, 4.0);
    onBorder.checkPointPosition();

    CircleAndPoint outside(5.0, 1.0, 1.0, 8.0, 6.0);
    outside.checkPointPosition();

    return 0;
}

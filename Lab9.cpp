#include <iostream>

using namespace std;

class Range {
private:
    int first;
    int second;

public:

    Range() : first(1), second(10) {
        cout << "[Конструктор за замовчуванням] Створено діапазон [1, 10)" << endl;
    }

    Range(int f, int s) : first(f), second(s) {
        cout << "[Конструктор ініціалізації] Створено діапазон [" << first << ", " << second << ")" << endl;
        if (!isValid()) {
            cout << "Попередження: задано некоректний інтервал (потрібно 0 < first < second)!" << endl;
        }
    }

    Range(int rightBound) : first(1), second(rightBound) {
        cout << "[Конструктор перетворення] Перетворено число " << rightBound
             << " у діапазон [" << first << ", " << second << ")" << endl;
    }

    Range(const Range& other) : first(other.first), second(other.second) {
        cout << "[Конструктор копіювання] Скопійовано діапазон [" << first << ", " << second << ")" << endl;
    }

    ~Range() {
        cout << "[Деструктор] Знищено об'єкт діапазону [" << first << ", " << second << ")" << endl;
    }

    void setFirst(int f) {
        first = f;
    }

    void setSecond(int s) {
        second = s;
    }

    void setRange(int f, int s) {
        first = f;
        second = s;
    }

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }

    bool isValid() const {
        return (first > 0) && (second > 0) && (first < second);
    }

    bool contains(int number) const {
        if (!isValid()) {
            cout << "Помилка: інтервал [" << first << ", " << second
                 << ") заданий некоректно (має бути 0 < first < second)!" << endl;
            return false;
        }
        return (number >= first) && (number < second);
    }

    void print() const {
        cout << "Діапазон: [" << first << ", " << second << ")";
        if (!isValid()) {
            cout << " [НЕКОРЕКТНИЙ]";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Лабораторна робота №9. Варіант 4 (Клас Range) ===" << endl << endl;

    Range r1(5, 15);
    r1.print();

    int testNumbers[] = {4, 5, 10, 15};
    for (int num : testNumbers) {
        cout << "Число " << num << (r1.contains(num) ? " НАЛЕЖИТЬ " : " НЕ належить ")
             << "діапазону [" << r1.getFirst() << ", " << r1.getSecond() << ")" << endl;
    }
    cout << endl;

    Range r2(r1);
    r2.setFirst(8);
    r2.setSecond(20);
    cout << "Після зміни меж через set-методи: ";
    r2.print();
    cout << "Перевірка числа 15 у новому діапазоні: "
         << (r2.contains(15) ? "НАЛЕЖИТЬ" : "НЕ належить") << endl << endl;

    Range r3 = 12;
    r3.print();
    cout << "Перевірка числа 11 у діапазоні r3: "
         << (r3.contains(11) ? "НАЛЕЖИТЬ" : "НЕ належить") << endl << endl;

    Range rInvalid(10, 5);
    rInvalid.contains(7);
    cout << endl;

    cout << "--- Завершення програми (виклик деструкторів) ---" << endl;
    return 0;
}
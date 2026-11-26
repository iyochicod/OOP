#include <iostream>
#include <string>

using namespace std;

enum scale { ounces, kilograms };

class ZooAnimal {
private:
    string name;
    int cageNumber;
    int weightDate;
    int weight;

public:

    ZooAnimal() : name("Nameless"), cageNumber(9999), weightDate(101), weight(100) {}

    ZooAnimal(string animalName, int whichCage, int weighDay, int pounds)
        : name(animalName), cageNumber(whichCage), weightDate(weighDay), weight(pounds) {}

    ~ZooAnimal() {}

    void Create(string animalName, int whichCage, int weighDay, int pounds);

    void Destroy();

    void changeWeight(int pounds);
    void changeWeightDate(int today);

    string reptName() const;

    int reptWeight() const;
    void reptWeight(scale which) const;

    int reptWeightDate() const;

    int daysSinceLastWeighed(int today) const;
};

void ZooAnimal::Create(string animalName, int whichCage, int weighDay, int pounds) {
    name = animalName;
    cageNumber = whichCage;
    weightDate = weighDay;
    weight = pounds;
}

void ZooAnimal::Destroy() {
    name.clear();
    cageNumber = 0;
    weightDate = 0;
    weight = 0;
}

string ZooAnimal::reptName() const {
    return name;
}

int ZooAnimal::reptWeight() const {
    return weight;
}

int ZooAnimal::reptWeightDate() const {
    return weightDate;
}

int ZooAnimal::daysSinceLastWeighed(int today) const {
    int startDay = (weightDate / 100) * 30 + (weightDate % 100);
    int currentDay = (today / 100) * 30 + (today % 100);
    return currentDay - startDay;
}

int main() {
    cout << "=== Завдання 1: Демонстрація класу ZooAnimal ===" << endl;

    ZooAnimal bozo;
    bozo.Create("Bozo", 408, 1027, 400);
    cout << "This animal's name is " << bozo.reptName() << endl;
    cout << "Weight date: " << bozo.reptWeightDate() << endl;
    cout << "Days since last weighed (today = 1115): "
         << bozo.daysSinceLastWeighed(1115) << " days" << endl;
    bozo.Destroy();

    ZooAnimal defaultAnimal;
    cout << "Default animal: " << defaultAnimal.reptName()
         << ", weight: " << defaultAnimal.reptWeight() << endl;

    ZooAnimal leo("Leo", 105, 510, 420);
    cout << "Parameterized animal: " << leo.reptName()
         << ", weight date: " << leo.reptWeightDate() << endl;

    return 0;
}

#include "basement.h"

int Bow::objectCount = 0;

string chooseBowString(const string& prompt, const string& currentMat) {
    int choice;
    string selectedMat;

    while (true) {
        cout << "\n" << prompt << endl;
        cout << "1 - Нейлон\n"
             << "2 - Шелк\n"
             << "3 - Лен\n"
             << "4 - Кевлар\n"
             << "5 - Дайнема\n"
             << "6 - Капрон\n"
             << "Ваш выбор (введите цифру от 1 до 6): ";

        if (!(cin >> choice)) {
            cin.clear();      
            string trash;             
            getline(cin, trash); 
            cout << "Ошибка ввода! Вводить можно только цифры от 1 до 6." << endl;
            continue;
        }

        switch (choice) {
            case 1: selectedMat = "Нейлон"; break;
            case 2: selectedMat = "Шелк"; break;
            case 3: selectedMat = "Лен"; break;
            case 4: selectedMat = "Кевлар"; break;
            case 5: selectedMat = "Дайнема"; break;
            case 6: selectedMat = "Капрон"; break;
            default:
                cout << "Ошибка! Такого варианта нет. Введите цифру в диапазоне от 1 до 6." << endl;
                continue;
        }

        if (!currentMat.empty() && selectedMat == currentMat) {
            cout << "Ошибка! На луке уже установлена тетива из материала [" << currentMat 
                 << "]. Пожалуйста, выберите другой вариант." << endl;
            continue;
        }

        return selectedMat;
    }
}

Bow::Bow() {
    string materials[] = {"Нейлон", "Шелк", "Лен", "Кевлар", "Дайнема", "Капрон"};
    strength = 10.0 + (rand() % 310) / 10.0;
    BowStringMat = materials[rand() % 6];
    objectCount++;
}

Bow::Bow(double str, string bsm) {
    strength = str;
    BowStringMat = bsm;
    objectCount++;
}

Bow::Bow(const Bow& other) {
    strength = other.strength;
    BowStringMat = other.BowStringMat;
    objectCount++;
}

Bow::~Bow() {
    objectCount--;
}

void Bow::restring(string bsm) {
    if (BowStringMat == bsm) {
        cout << "Эта тетива (" << bsm << ") уже установлена на луке!" << endl;
        return;
    }

    cout << "\nПопытка сменить тетиву с [" << BowStringMat << "] на [" << bsm << "]..." << endl;
    
    if (rand() % 2 == 0) {
        BowStringMat = bsm;
        cout << "Успех! Тетива успешно заменена на: " << BowStringMat << endl;
    } else {
        BowStringMat = "Отсутствует (порвана)";
        cout << "Неудача! Новая тетива (" << bsm << ") не выдержала натяжения и лопнула при установке!" << endl;
    }
}

void Bow::test() const {
    cout << "(Тест лука) Натяжение: " << strength 
         << " кг | Материал тетивы: " << BowStringMat << endl;
}

int Bow::getObjectCount() {
    return objectCount;
}

void inspectBow(const Bow& b) {
    cout << "(Дружественная функция inspectBow) Сила = " << b.strength 
         << ", Материал = " << b.BowStringMat << endl;
}

SelfManagedBow::SelfManagedBow(double str, string bsm) : strength(str), BowStringMat(bsm) {}
SelfManagedBow::~SelfManagedBow() {}

SelfManagedBow* SelfManagedBow::createObject(double str, string bsm) {
    return new SelfManagedBow(str, bsm);
}

SelfManagedBow* SelfManagedBow::createRandomObject() {
    string materials[] = {"Нейлон", "Шелк", "Лен", "Кевлар", "Дайнема", "Капрон"};
    double randomStrength = 10.0 + (rand() % 310) / 10.0;
    string randomMat = materials[rand() % 6];
    return new SelfManagedBow(randomStrength, randomMat);
}

void SelfManagedBow::destroyObject(SelfManagedBow* ptr) {
    delete ptr;
}

void SelfManagedBow::test() const {
    cout << "(SelfManagedBow) Сила: " << strength << " | Тетива: " << BowStringMat << endl;
}

FriendManagedBow::FriendManagedBow(double str, string bsm) : strength(str), BowStringMat(bsm) {}
FriendManagedBow::~FriendManagedBow() {}

void FriendManagedBow::test() const {
    cout << "(FriendManagedBow) Сила: " << strength << " | Тетива: " << BowStringMat << endl;
}

FriendManagedBow* createFriendBow(double str, string bsm) {
    return new FriendManagedBow(str, bsm);
}

FriendManagedBow* createRandomFriendBow() {
    string materials[] = {"Нейлон", "Шелк", "Лен", "Кевлар", "Дайнема", "Капрон"};
    double randomStrength = 10.0 + (rand() % 310) / 10.0;
    string randomMat = materials[rand() % 6];
    return new FriendManagedBow(randomStrength, randomMat);
}

void destroyFriendBow(FriendManagedBow* ptr) {
    delete ptr;
}
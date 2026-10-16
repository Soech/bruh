#include "basement.h"

int Bow::objectCount = 0;

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
    BowStringMat = bsm;
    cout << "Тетива успешно заменена на: " << BowStringMat << endl;
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
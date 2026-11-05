#include "basement.h"

int inputNumber(string prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << prompt;
        if (!(cin >> val)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Ошибка! Введите число от " << minVal << " до " << maxVal << "." << endl;
            continue;
        }
        if (val < minVal || val > maxVal) {
            cout << "Ошибка! Диапазон от " << minVal << " до " << maxVal << "." << endl;
            continue;
        }
        return val;
    }
}

string inputGender(int roomNum) {
    int choice;
    while (true) {
        cout << "Кто поселен в комнату №" << roomNum << "? (1 - Мужчина, 2 - Женщина): ";
        if (!(cin >> choice)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Ошибка! Введите 1 или 2." << endl;
            continue;
        }
        if (choice == 1) return "Мужчина";
        if (choice == 2) return "Женщина";
        cout << "Ошибка! Выберите 1 или 2." << endl;
    }
}

Room::Room() {
    roomNumber = 0;
    floor = 1;
    totalBeds = 1;
    occupiedBeds = 0;
    isReserved = false;
    gender = "Нет";
}

Room::Room(int num, int fl, int total, int occ, bool res, string gen) {
    roomNumber = num;
    floor = fl;
    totalBeds = total;
    occupiedBeds = occ;
    isReserved = res;
    gender = gen;
}

Room::Room(const Room& other) {
    roomNumber = other.roomNumber;
    floor = other.floor;
    totalBeds = other.totalBeds;
    occupiedBeds = other.occupiedBeds;
    isReserved = other.isReserved;
    gender = other.gender;
}

Room& Room::operator=(const Room& r) {
    roomNumber = r.roomNumber;
    floor = r.floor;
    totalBeds = r.totalBeds;
    occupiedBeds = r.occupiedBeds;
    isReserved = r.isReserved;
    gender = r.gender;
    return *this;
}

bool Room::operator==(const Room& r) {
    return occupiedBeds == r.occupiedBeds;
}

Room Room::operator+(int beds) {
    Room temp(*this);
    temp.occupiedBeds += beds;
    if (temp.occupiedBeds > temp.totalBeds) {
        temp.occupiedBeds = temp.totalBeds;
    }
    return temp;
}

Room Room::operator+(const Room& r) {
    Room temp(*this);
    temp.totalBeds += r.totalBeds;
    temp.occupiedBeds += r.occupiedBeds;
    return temp;
}

ostream& operator<<(ostream& out, const Room& r) {
    out << "Комната №" << r.roomNumber
        << " | Этаж: " << r.floor
        << " | Мест (занято/всего): " << r.occupiedBeds << "/" << r.totalBeds
        << " | Бронь: " << (r.isReserved ? "Да" : "Нет")
        << " | Проживает: " << r.gender;
    return out;
}

Hotel::Hotel(int c) {
    count = c;
}

Room& Hotel::operator[](int index) {
    return rooms[index];
}

int Hotel::getTotalOccupied() {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += rooms[i].getOccupiedBeds();
    }
    return sum;
}

void Hotel::showReserved() {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (rooms[i].getIsReserved()) {
            cout << rooms[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Забронированных номеров нет." << endl;
    }
}
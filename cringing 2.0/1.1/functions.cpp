#include "basement.h"
DriverRecord::DriverRecord() {
    employeeId = 0;
    fullName = "";
    birthYear = 0;
    experience = 0;
    licensePlate = "";
    note = "";
}

DriverRecord::DriverRecord(int id, string name, int year, int exp, string plate, string n) {
    employeeId = id;
    fullName = name;
    birthYear = year;
    experience = exp;
    licensePlate = plate;
    note = n;
}

void DriverRecord::printInfo() const {
    cout << "Таб. №: " << employeeId 
         << " | ФИО: " << fullName 
         << " | Год: " << birthYear 
         << " | Стаж: " << experience << " лет"
         << " | Номер: " << licensePlate 
         << " | Прим.: " << note << endl;
}

bool isValidUpperInput(const string& str) {
    if (str.empty()) return false;

    // 1. Проверка на отсутствие цифр
    for (char c : str) {
        if (isdigit(static_cast<unsigned char>(c))) return false;
    }

    unsigned char b1 = static_cast<unsigned char>(str[0]);

    // 2. Английская заглавная
    if (b1 >= 'A' && b1 <= 'Z') return true;

    // 3. Русская заглавная в UTF-8
    if (b1 == 0xD0 && str.length() >= 2) {
        unsigned char b2 = static_cast<unsigned char>(str[1]);
        if ((b2 >= 0x80 && b2 <= 0x9F) || b2 == 0x81) {
            return true;
        }
    }

    return false;
}

void generateRandomDrivers(DriverRecord drivers[], int size) {
    string names[] = {
        "Иванов И. И.", "Петров П. П.", "Ильин А. В.", "Сидоров С. С.", "Алексеев М. А.",
        "Игнатов В. С.", "Павлов Д. Н.", "Смирнов Е. О.", "Исаев Г. К.", "Николаев Т. В."
    };

    string notes[] = {"Опытный", "Без нарушений", "Наставник", "Стажер", "Сменный график"};
    string letters[] = {"А", "В", "Е", "К", "М", "Н", "О", "Р", "С", "Т", "У", "Х"};

    for (int i = 0; i < size; ++i) {
        int id = 101 + i;
        string name = names[i % 10];
        
        int exp = rand() % 36;              
        int birth = 2026 - 18 - exp - (rand() % 15);
        
        string l1 = letters[rand() % 12];
        string l2 = letters[rand() % 12];
        string l3 = letters[rand() % 12];
        int num = 100 + rand() % 900;
        
        string plate = l1 + to_string(num) + l2 + l3 + "761";
        string note = notes[rand() % 5];

        drivers[i] = DriverRecord(id, name, birth, exp, plate, note);
    }
}

void printAllDrivers(const DriverRecord drivers[], int size) {
    cout << "\n=== Полный список водителей ===\n";
    for (int i = 0; i < size; ++i) {
        drivers[i].printInfo();
    }
}

void filterByExperience(const DriverRecord drivers[], int size, int minExp) {
    cout << "\n=== Водители со стажем более " << minExp << " лет ===\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (drivers[i].getExperience() > minExp) {
            drivers[i].printInfo();
            found = true;
        }
    }
    if (!found) cout << "Не найдено.\n";
}

void filterByFirstLetter(const DriverRecord drivers[], int size, const string& letterPrefix) {
    cout << "\n=== Поиск водителей по запросу '" << letterPrefix << "' ===\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        string name = drivers[i].getFullName();
        if (name.rfind(letterPrefix, 0) == 0) {
            drivers[i].printInfo();
            found = true;
        }
    }
    if (!found) cout << "Водители по данному запросу не найдены.\n";
}
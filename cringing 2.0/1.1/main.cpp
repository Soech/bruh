#include "basement.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(0)));
    const int DRIVER_COUNT = 8;
    DriverRecord drivers[DRIVER_COUNT];
    generateRandomDrivers(drivers, DRIVER_COUNT);
    printAllDrivers(drivers, DRIVER_COUNT);
    filterByExperience(drivers, DRIVER_COUNT, 20);
    string searchQuery;
    while (true) {
        cout << "\nВведите ЗАГЛАВНУЮ букву или начало фамилии для поиска (например, 'И' или 'Пе'): ";
        cin >> searchQuery;

        if (!isValidUpperInput(searchQuery)) {
            cout << "Ошибка! Ввод не должен содержать цифр и должен НАЧИНАТЬСЯ С ЗАГЛАВНОЙ БУКВЫ. Попробуйте снова.\n";
            continue;
        }

        break;
    }

    filterByFirstLetter(drivers, DRIVER_COUNT, searchQuery);

    return 0;
}
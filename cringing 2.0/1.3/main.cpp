#include "basement.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(0)));

    int count = inputNumber("Введите количество комнат (от 1 до 10): ", 1, 10);
    Hotel h(count);

    for (int i = 0; i < count; i++) {
        int roomNum = i + 1;
        int floor = (i / 5) + 1;

        cout << "\n--- Настройка комнаты №" << roomNum << " ---" << endl;
        int totalBeds = inputNumber("Введите количество спальных мест (1-6): ", 1, 6);

        int occupiedBeds = rand() % (totalBeds + 1);
        bool isReserved = rand() % 2;

        string gender = "Никто не заселен";
        if (occupiedBeds > 0) {
            gender = inputGender(roomNum);
        } else {
            cout << "Свободных мест " << totalBeds << " из " << totalBeds << " (выпало 0 занятых мест)." << endl;
        }

        h[i] = Room(roomNum, floor, totalBeds, occupiedBeds, isReserved, gender);
    }

    cout << "\nВСЕ НОМЕРА ГОСТИНИЦЫ:" << endl;
    for (int i = 0; i < h.getCount(); i++) {
        cout << h[i] << endl;
    }

    cout << "\nОбщее количество занятых спальных мест: " << h.getTotalOccupied() << endl;

    cout << "\nСписок номеров с бронью:" << endl;
    h.showReserved();

    cout << "\nПРОВЕРКА ПЕРЕГРУЖЕННЫХ ОПЕРАЦИЙ:" << endl;
    Room r1 = h[0] + 1;
    cout << "Комната №1 (+1 занятое место): " << r1 << endl;

    if (count > 1) {
        Room r2 = h[0] + h[1];
        cout << "Сложение мест комнат №1 и №2: " << r2 << endl;

        if (h[0] == h[1]) {
            cout << "В комнатах №1 и №2 одинаковое число занятых мест" << endl;
        } else {
            cout << "В комнатах №1 и №2 разное число занятых мест" << endl;
        }
    }

    return 0;
}
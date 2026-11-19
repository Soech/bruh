#include "Header.h"

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(0)));

    string cities[4] = { "Ростов-на-Дону", "Москва", "Сочи", "Казань" };
    string depTimes[4] = { "08:00", "12:30", "16:00", "20:15" };
    string arrTimes[4] = { "10:00", "14:45", "18:30", "22:30" };
    string flightCodes[4] = { "FL-101", "FL-202", "FL-303", "FL-404" };
    int seatOptions[4] = { 120, 150, 180, 210 };

    Pilot pilots[4] = {
        Pilot("Иванов И.И."),
        Pilot("Петров П.П."),
        Pilot("Сидоров С.С."),
        Pilot("Смирнов А.А.")
    };

    Airport airport(
        Airline("Аэрофлот"),
        Airline("S7 Airlines"),
        Airline("Utair")
    );

    int totalFlights = inputChoice("Сколько рейсов хотите оформить? (1-4): ", 1, 4);

    for (int i = 0; i < totalFlights; i++) {
        cout << "\n--- ОФОРМЛЕНИЕ РЕЙСА №" << i + 1 << " ---" << endl;

        cout << "Выберите город отправления:" << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << " - " << cities[j] << endl;
        }
        int depChoice = inputChoice("Ваш выбор (1-4): ", 1, 4);
        string depCity = cities[depChoice - 1];

        cout << "\nКуда можно вылететь из г. " << depCity << ":" << endl;
        string availableCities[3];
        int idx = 0;
        for (int j = 0; j < 4; j++) {
            if (cities[j] != depCity) {
                availableCities[idx] = cities[j];
                cout << idx + 1 << " - " << availableCities[idx] << endl;
                idx++;
            }
        }
        int destChoice = inputChoice("Выберите город назначения (1-3): ", 1, 3);
        string destCity = availableCities[destChoice - 1];

        int timeIdx = rand() % 4;
        int seats = seatOptions[rand() % 4];
        Pilot* randomPilot = &pilots[rand() % 4];
        int airlineIdx = rand() % 3;

        Flight newFlight(
            flightCodes[i],
            depCity,
            destCity,
            depTimes[timeIdx],
            arrTimes[timeIdx],
            seats,
            randomPilot
        );

        airport.airlines[airlineIdx].addFlight(newFlight);

        cout << "-> Рейс успешно создан! Назначена компания: " << airport.airlines[airlineIdx].name << endl;
        newFlight.show();
    }

    while (true) {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1 - Показать расписание всех рейсов" << endl;
        cout << "2 - Показать информацию о пилотах" << endl;
        cout << "3 - Просмотр рейсов по транспортным компаниям" << endl;
        cout << "0 - Закончить программу" << endl;

        int mainChoice = inputChoice("Ваш выбор (0-3): ", 0, 3);

        if (mainChoice == 0) {
            cout << "Программа завершена." << endl;
            break;
        }
        else if (mainChoice == 1) {
            airport.showSchedule();
        }
        else if (mainChoice == 2) {
            airport.showPilots();
        }
        else if (mainChoice == 3) {
            while (true) {
                cout << "\n--- ВЫБЕРИТЕ ТРАНСПОРТНУЮ КОМПАНИЮ ---" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << " - " << airport.airlines[i].name << endl;
                }
                cout << "4 - Выйти в главное меню" << endl;
                cout << "0 - Закончить программу" << endl;

                int searchChoice = inputChoice("Ваш выбор (0-4): ", 0, 4);

                if (searchChoice == 0) {
                    cout << "Программа завершена." << endl;
                    return 0;
                }
                else if (searchChoice == 4) {
                    break;
                }
                else {
                    airport.findAirline(airport.airlines[searchChoice - 1].name);
                }
            }
        }
    }

    return 0;
}
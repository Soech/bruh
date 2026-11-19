#include "Header.h"

int inputChoice(string prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << prompt;
        if (!(cin >> val) || cin.peek() != '\n') {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Ошибка! Введите только цифру пункта (от " << minVal << " до " << maxVal << ") без букв." << endl;
            continue;
        }
        if (val < minVal || val > maxVal) {
            cout << "Ошибка! Выберите пункт от " << minVal << " до " << maxVal << "." << endl;
            continue;
        }
        return val;
    }
}

Pilot::Pilot() {
    name = "Не назначен";
}

Pilot::Pilot(string n) {
    name = n;
}

void Pilot::show() {
    cout << "Пилот: " << name;
}

SeatMap::SeatMap() {
    totalSeats = 0;
}

SeatMap::SeatMap(int s) {
    totalSeats = s;
}

void SeatMap::show() {
    cout << "Мест: " << totalSeats;
}

Flight::Flight() {
    flightNumber = "-";
    departure = "-";
    destination = "-";
    departureTime = "-";
    arrivalTime = "-";
    seatMap = SeatMap(0);
    pilot = nullptr;
}

Flight::Flight(string num, string dep, string dest, string depTime, string arrTime, int seats, Pilot* p) {
    flightNumber = num;
    departure = dep;
    destination = dest;
    departureTime = depTime;
    arrivalTime = arrTime;
    seatMap = SeatMap(seats);
    pilot = p;
}

void Flight::show() {
    cout << "  Рейс " << flightNumber << " | " << departure << " -> " << destination
        << " | Время: " << departureTime << " - " << arrivalTime << " | ";
    seatMap.show();
    cout << " | ";
    if (pilot != nullptr) {
        pilot->show();
    }
    cout << endl;
}

Airline::Airline() {
    name = "-";
    flightCount = 0;
}

Airline::Airline(string n) {
    name = n;
    flightCount = 0;
}

void Airline::addFlight(Flight f) {
    if (flightCount < 5) {
        flights[flightCount] = f;
        flightCount++;
    }
}

void Airline::show() {
    cout << "Транспортная компания: " << name << endl;
    if (flightCount == 0) {
        cout << "  Рейсов пока нет." << endl;
    }
    for (int i = 0; i < flightCount; i++) {
        flights[i].show();
    }
}

Airport::Airport() {}

Airport::Airport(Airline a1, Airline a2, Airline a3) {
    airlines[0] = a1;
    airlines[1] = a2;
    airlines[2] = a3;
}

void Airport::showSchedule() {
    cout << "\n=== РАСПИСАНИЕ РЕЙСОВ АЭРОПОРТА ===" << endl;
    for (int i = 0; i < 3; i++) {
        airlines[i].show();
    }
}

void Airport::findAirline(string airlineName) {
    cout << "\n=== ПОИСК АВИАКОМПАНИИ: " << airlineName << " ===" << endl;
    for (int i = 0; i < 3; i++) {
        if (airlines[i].name == airlineName) {
            airlines[i].show();
            return;
        }
    }
    cout << "Авиакомпания не найдена." << endl;
}

void Airport::showPilots() {
    cout << "\n=== НАЗНАЧЕННЫЕ ПИЛОТЫ НА РЕЙСАХ ===" << endl;
    bool hasFlights = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < airlines[i].flightCount; j++) {
            if (airlines[i].flights[j].pilot != nullptr) {
                cout << "Рейс " << airlines[i].flights[j].flightNumber
                    << " (" << airlines[i].name << ") -> ";
                airlines[i].flights[j].pilot->show();
                cout << endl;
                hasFlights = true;
            }
        }
    }
    if (!hasFlights) {
        cout << "Активных рейсов нет." << endl;
    }
}
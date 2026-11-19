#include "Header.h"

int inputChoice(string prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << prompt;
        if (!(cin >> val) || cin.peek() != '\n') {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Îøèáêà! Ââåäèòå òîëüêî öèôðó ïóíêòà (îò " << minVal << " äî " << maxVal << ") áåç áóêâ." << endl;
            continue;
        }
        if (val < minVal || val > maxVal) {
            cout << "Îøèáêà! Âûáåðèòå ïóíêò îò " << minVal << " äî " << maxVal << "." << endl;
            continue;
        }
        return val;
    }
}

Pilot::Pilot() {
    name = "Íå íàçíà÷åí";
}

Pilot::Pilot(string n) {
    name = n;
}

void Pilot::show() {
    cout << "Ïèëîò: " << name;
}

SeatMap::SeatMap() {
    totalSeats = 0;
}

SeatMap::SeatMap(int s) {
    totalSeats = s;
}

void SeatMap::show() {
    cout << "Ìåñò: " << totalSeats;
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
    cout << "  Ðåéñ " << flightNumber << " | " << departure << " -> " << destination
        << " | Âðåìÿ: " << departureTime << " - " << arrivalTime << " | ";
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
    cout << "Òðàíñïîðòíàÿ êîìïàíèÿ: " << name << endl;
    if (flightCount == 0) {
        cout << "  Ðåéñîâ ïîêà íåò." << endl;
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
    cout << "\n=== ÐÀÑÏÈÑÀÍÈÅ ÐÅÉÑÎÂ ÀÝÐÎÏÎÐÒÀ ===" << endl;
    for (int i = 0; i < 3; i++) {
        airlines[i].show();
    }
}

void Airport::findAirline(string airlineName) {
    cout << "\n=== ÏÎÈÑÊ ÀÂÈÀÊÎÌÏÀÍÈÈ: " << airlineName << " ===" << endl;
    for (int i = 0; i < 3; i++) {
        if (airlines[i].name == airlineName) {
            airlines[i].show();
            return;
        }
    }
    cout << "Àâèàêîìïàíèÿ íå íàéäåíà." << endl;
}

void Airport::showPilots() {
    cout << "\n=== ÍÀÇÍÀ×ÅÍÍÛÅ ÏÈËÎÒÛ ÍÀ ÐÅÉÑÀÕ ===" << endl;
    bool hasFlights = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < airlines[i].flightCount; j++) {
            if (airlines[i].flights[j].pilot != nullptr) {
                cout << "Ðåéñ " << airlines[i].flights[j].flightNumber
                    << " (" << airlines[i].name << ") -> ";
                airlines[i].flights[j].pilot->show();
                cout << endl;
                hasFlights = true;
            }
        }
    }
    if (!hasFlights) {
        cout << "Àêòèâíûõ ðåéñîâ íåò." << endl;
    }
}
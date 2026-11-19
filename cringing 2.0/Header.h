#ifndef BASEMENT_H
#define BASEMENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int inputChoice(string prompt, int minVal, int maxVal);

class Pilot {
public:
    string name;

    Pilot();
    Pilot(string n);
    void show();
};

class SeatMap {
public:
    int totalSeats;

    SeatMap();
    SeatMap(int s);
    void show();
};

class Flight {
public:
    string flightNumber;
    string departure;
    string destination;
    string departureTime;
    string arrivalTime;
    SeatMap seatMap;
    Pilot* pilot;

    Flight();
    Flight(string num, string dep, string dest, string depTime, string arrTime, int seats, Pilot* p);
    void show();
};

class Airline {
public:
    string name;
    Flight flights[5];
    int flightCount;

    Airline();
    Airline(string n);
    void addFlight(Flight f);
    void show();
};

class Airport {
public:
    Airline airlines[3];

    Airport();
    Airport(Airline a1, Airline a2, Airline a3);
    void showSchedule();
    void findAirline(string airlineName);
    void showPilots();
};

#endif
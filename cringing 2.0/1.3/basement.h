#ifndef BASEMENT_H
#define BASEMENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int inputNumber(string prompt, int minVal, int maxVal);
string inputGender(int roomNum);

class Room {
private:
    int roomNumber;
    int floor;
    int totalBeds;
    int occupiedBeds;
    bool isReserved;
    string gender;

public:
    Room();
    Room(int num, int fl, int total, int occ, bool res, string gen);
    Room(const Room& other);

    int getRoomNumber() { return roomNumber; }
    int getFloor() { return floor; }
    int getTotalBeds() { return totalBeds; }
    int getOccupiedBeds() { return occupiedBeds; }
    bool getIsReserved() { return isReserved; }
    string getGender() { return gender; }

    void setRoomNumber(int num) { roomNumber = num; }
    void setFloor(int fl) { floor = fl; }
    void setTotalBeds(int total) { totalBeds = total; }
    void setOccupiedBeds(int occ) { occupiedBeds = occ; }
    void setIsReserved(bool res) { isReserved = res; }
    void setGender(string gen) { gender = gen; }

    Room& operator=(const Room& r);
    bool operator==(const Room& r);
    Room operator+(int beds);
    Room operator+(const Room& r);

    friend ostream& operator<<(ostream& out, const Room& r);
};

class Hotel {
private:
    Room rooms[10];
    int count;

public:
    Hotel(int c);
    int getCount() { return count; }

    Room& operator[](int index);
    int getTotalOccupied();
    void showReserved();
};

#endif
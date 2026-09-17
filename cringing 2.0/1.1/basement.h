#ifndef BASEMENT_H
#define BASEMENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <windows.h>

using namespace std;

class DriverRecord {
private:
    int employeeId;          
    string fullName;         
    int birthYear;           
    int experience;          
    string licensePlate;     
    string note;             

public:
    DriverRecord();
    DriverRecord(int id, string name, int year, int exp, string plate, string n);
    int getEmployeeId() const { return employeeId; }
    string getFullName() const { return fullName; }
    int getBirthYear() const { return birthYear; }
    int getExperience() const { return experience; }
    string getLicensePlate() const { return licensePlate; }
    string getNote() const { return note; }

    void setEmployeeId(int id) { employeeId = id; }
    void setFullName(string name) { fullName = name; }
    void setBirthYear(int year) { birthYear = year; }
    void setExperience(int exp) { experience = exp; }
    void setLicensePlate(string plate) { licensePlate = plate; }
    void setNote(string n) { note = n; }

    void printInfo() const;
};

bool isValidUpperInput(const string& str);
void generateRandomDrivers(DriverRecord drivers[], int size);
void printAllDrivers(const DriverRecord drivers[], int size);
void filterByExperience(const DriverRecord drivers[], int size, int minExp = 20);
void filterByFirstLetter(const DriverRecord drivers[], int size, const string& letterPrefix);

#endif
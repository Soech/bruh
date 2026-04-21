#ifndef BAZA_H
#define BAZA_H

#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

struct Employee {
    string fio;
    string pos; // должность
    int otdl;   // отдел
    int year;   // год начала
};

Employee* createArray(int n);
void fillData(Employee* arr, int n);
void displayByDept(Employee* arr, int n, int target);
int getInt();

#endif
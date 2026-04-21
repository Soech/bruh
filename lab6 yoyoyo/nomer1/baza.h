#ifndef BAZA_H
#define BAZA_H

#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

struct Movie {
    string title;
    string director;
    double price;
};

// Прототипы по заданию
Movie* createArray(int n);
void fillData(Movie* m, int n);
void display(Movie* m, int n);
int getInt();

#endif
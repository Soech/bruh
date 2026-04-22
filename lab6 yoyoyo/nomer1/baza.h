#ifndef BAZA_H
#define BAZA_H

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Movies {
    string title;
    string producer;
    string price;
};

int proverka();
Movies* createArray(int n);
void fillin(Movies* list, int n);
void PrintSortedMovies(Movies* list, int n);

#endif
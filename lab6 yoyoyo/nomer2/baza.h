#ifndef BAZA_H
#define BAZA_H
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Employers{
    string fio;
    string dolg;
    int otdl;
    int year;
};

int proverkaint();
Employers* createArray(int n);
void fillin(Employers* list, int n);
void showOtdl(Employers* list, int n, int d);

#endif
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Структура для хранения данных о студенте
struct Student {
    string lastName;
    int mathGrade;
    int infoGrade;
    int physGrade;
};

// Прототипы функций
int inputInt(string message, int minVal, int maxVal);
void inputGradesManual(Student* students, int count);
void printStudents(Student* students, int count);
void printExcellentStudents(Student* students, int count);

#endif
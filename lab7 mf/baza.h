#ifndef BAZA_H
#define BAZA_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

struct Visit {
    string ip;
    string time;
    string day;
};

void createStatsFile(const string& filename);
void createStudentFile(const string& filename);
bool isFileValid(const string& filename);
void processWebsiteStats(const string& input, const string& output);
void processStudentList(const string& input, const string& output);

#endif
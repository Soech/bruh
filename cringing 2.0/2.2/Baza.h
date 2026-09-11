#ifndef BAZA_H
#define BAZA_H

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

struct PRICE {
    string TOVAR; // Название товара
    string MAG;   // Название магазина
    int STOIM;    // Стоимость в рублях
};

int inputInt(string message, int minVal, int maxVal);
void loadFixedCatalog(PRICE* spisok, int count);
void sortSpisokByShop(PRICE* spisok, int count);
void printSpisok(PRICE* spisok, int count);
void findGoodsByShop(PRICE* spisok, int count, string searchShop);
string toLowerUTF8(string str);

#endif
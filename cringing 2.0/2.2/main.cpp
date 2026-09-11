#include "Baza.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Программа работы с каталогом PRICE ===" << endl;

    int count = inputInt("Введите количество товаров (от 1 до 10): ", 1, 10);

    PRICE* SPISOK = new PRICE[count];

    loadFixedCatalog(SPISOK, count);

    sortSpisokByShop(SPISOK, count);

    printSpisok(SPISOK, count);
    
    string searchShop;
    cout << "\nВведите название магазина для поиска: ";
    getline(cin, searchShop);

    findGoodsByShop(SPISOK, count, searchShop);

    delete[] SPISOK;

    return 0;
}
#include "Baza.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Программа работы с каталогом PRICE ===" << endl;

    int count = inputInt("Введите количество товаров (от 1 до 10): ", 1, 10);

    // Динамический массив
    PRICE* SPISOK = new PRICE[count];

    // Автоматическая загрузка фиксированного каталога
    loadFixedCatalog(SPISOK, count);

    // Сортировка записей в алфавитном порядке по магазинам
    sortSpisokByShop(SPISOK, count);

    // Вывод отсортированного списка
    printSpisok(SPISOK, count);

    // Ввод магазина для поиска
    string searchShop;
    cout << "\nВведите название магазина для поиска: ";
    getline(cin, searchShop);

    findGoodsByShop(SPISOK, count, searchShop);

    // Освобождение памяти
    delete[] SPISOK;

    return 0;
}
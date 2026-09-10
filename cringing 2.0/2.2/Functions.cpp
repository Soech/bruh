#include "Baza.h"

// Список из 10 фиксированных товаров с ценами в целых числах
const PRICE FIXED_CATALOG[10] = {
    {"Хлеб", "Магнит", 45},
    {"Молоко", "Пятерочка", 89},
    {"Ноутбук", "ДНС", 65000},
    {"Яблоки", "Магнит", 120},
    {"Кофе", "Перекресток", 450},
    {"Телевизор", "МВидео", 32000},
    {"Чай", "Пятерочка", 180},
    {"Смартфон", "ДНС", 25000},
    {"Шоколад", "Перекресток", 95},
    {"Наушники", "МВидео", 4900}
};

string toLowerUTF8(string str) {
    if (str.empty()) return str;

    int wlen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    if (wlen <= 0) return str;

    // Используем static_cast<size_t>
    wstring wstr(static_cast<size_t>(wlen), 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], wlen);

    // Используем static_cast<DWORD>
    CharLowerBuffW(&wstr[0], static_cast<DWORD>(wlen));

    int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    if (len <= 0) return str;

    // Используем static_cast<size_t>
    string result(static_cast<size_t>(len - 1), 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &result[0], len, NULL, NULL);

    return result;
}

// Проверка ввода целых чисел через cin.fail()
int inputInt(string message, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << message;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка ввода! Введите целое число от " << minVal << " до " << maxVal << "." << endl;
        } else {
            cin.ignore(32767, '\n');
            return value;
        }
    }
}

// Копирование фиксированного каталога в массив
void loadFixedCatalog(PRICE* spisok, int count) {
    for (int i = 0; i < count; i++) {
        spisok[i] = FIXED_CATALOG[i % 10];
    }
}

// Сортировка пузырьком по названию магазина (в алфавитном порядке)
void sortSpisokByShop(PRICE* spisok, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (spisok[j].MAG > spisok[j + 1].MAG) {
                PRICE temp = spisok[j];
                spisok[j] = spisok[j + 1];
                spisok[j + 1] = temp;
            }
        }
    }
}

// Вывод всего списка товаров
void printSpisok(PRICE* spisok, int count) {
    cout << "\n---------------- КАТАЛОГ ТОВАРОВ (Отсортирован по магазинам) ----------------\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". Магазин: " << spisok[i].MAG 
             << " | Товар: " << spisok[i].TOVAR 
             << " | Цена: " << spisok[i].STOIM << " руб." << endl;
    }
    cout << "-----------------------------------------------------------------------------\n";
}

// Поиск товаров в заданном магазине (без учета регистра)
void findGoodsByShop(PRICE* spisok, int count, string searchShop) {
    bool found = false;
    cout << "\nРезультаты поиска для магазина \"" << searchShop << "\":" << endl;

    // Приводим искомый магазин к нижнему регистру
    string searchLower = toLowerUTF8(searchShop);

    for (int i = 0; i < count; i++) {
        // Приводим название магазина из структуры к нижнему регистру для сравнения
        if (toLowerUTF8(spisok[i].MAG) == searchLower) {
            cout << "- Товар: " << spisok[i].TOVAR << " | Цена: " << spisok[i].STOIM << " руб." << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Сообщение: Магазин \"" << searchShop << "\" в списке не найден!" << endl;
    }
}
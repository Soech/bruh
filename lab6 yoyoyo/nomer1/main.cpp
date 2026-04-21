#include "baza.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите количество фильмов: ";
    int n = getInt();

    Movie* list = createArray(n);
    fillData(list, n);
    display(list, n);

    delete[] list;
    return 0;
}
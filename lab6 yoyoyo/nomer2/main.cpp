#include "baza.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите число сотрудников: ";
    int n = getInt();

    Employee* list = createArray(n);
    fillData(list, n);

    cout << "\nКакой отдел вывести? ";
    int d = getInt();
    displayByDept(list, n, d);

    delete[] list;
    return 0;
}
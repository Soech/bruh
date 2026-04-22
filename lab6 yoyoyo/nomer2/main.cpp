#include "baza.h"
int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Введите число сотрудников: ";
    int n = proverkaint();

    Employers* list = createArray(n);
    fillin(list, n);

    cout << "\n Номер отдела для поиска: ";
    int d = proverkaint();
    showOtdl(list, n, d);

    delete[] list;
    return 0;
}
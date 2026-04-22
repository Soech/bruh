#include "baza.h"

int proverkaint(){
    int value;
    while (true) { if (cin >> value && value >= 0)
    return value;
    cout << "Ошибка! Введите число: ";
    cin.clear();
    cin.ignore(1000, '\n');
    }
}

Employers* createArray(int n){return new Employers[n];}

void fillin(Employers* list, int n){
    for (int i = 0; i < n; i++){
        cout << "\n Сотрудник " << i + 1 << endl;
        cin.ignore(1000, '\n');
        cout << "ФИО: "; getline(cin, list[i].fio);
        cout << "Должность: "; getline(cin, list[i].dolg);
        cout << "Отдел: "; list[i].otdl = proverkaint();
        cout << "Год: "; list[i].year = proverkaint();
    }
}

void showOtld(Employers* list, int n, int d){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (list[j].year > list[j+1].year) swap(list[j], list[j+1]);
        }
    }
    cout << "\n Отдел \n" << d << endl;
    for (int i = 0; i < n; i++){
        if (list[i].otdl == d){
            cout << list[i].fio << " | " << list[i].dolg << " | " << list[i].year << "года" << endl;
        }
    }
}
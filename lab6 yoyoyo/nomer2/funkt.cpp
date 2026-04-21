#include "baza.h"

int getInt() {
    int v;
    while (!(cin >> v)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return v;
}

Employee* createArray(int n) { return new Employee[n]; }

void fillData(Employee* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nСотрудник " << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ФИО: "; getline(cin, arr[i].fio);
        cout << "Должность: "; getline(cin, arr[i].pos);
        cout << "Отдел: "; arr[i].otdl = getInt();
        cout << "Год старта: "; arr[i].year = getInt();
    }
}

void displayByDept(Employee* arr, int n, int target) {
    // Сортировка по стажу (меньший год = выше в списке)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].year > arr[j + 1].year) swap(arr[j], arr[j + 1]);
        }
    }
    cout << "\n--- Отдел " << target << " (по стажу) ---" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].otdl == target) {
            cout << arr[i].fio << " | " << arr[i].pos << " | С " << arr[i].year << "г." << endl;
        }
    }
}
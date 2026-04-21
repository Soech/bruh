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

Movie* createArray(int n) { return new Movie[n]; }

void fillData(Movie* m, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nФильм " << i + 1 << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Название: "; getline(cin, m[i].title);
        cout << "Режиссер: "; getline(cin, m[i].director);
        cout << "Цена: "; cin >> m[i].price;
    }
}

void display(Movie* m, int n) {
    // Сортировка пузырьком
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j].price > m[j + 1].price) swap(m[j], m[j + 1]);
        }
    }
    cout << "\n--- Видеотека (по цене) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << m[i].title << " | " << m[i].director << " | " << m[i].price << " руб." << endl;
    }
}
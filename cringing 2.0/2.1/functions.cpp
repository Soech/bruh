#include "base.h"

const string FIXED_NAMES[6] = {
    "Иванов", 
    "Петров", 
    "Сидоров", 
    "Смирнова", 
    "Кузнецов", 
    "Попов"
};

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

void inputGradesManual(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].lastName = FIXED_NAMES[i % 6];
        cout << "\nСтудент: " << students[i].lastName << endl;
        students[i].mathGrade = inputInt("Оценка по математике (2-5): ", 2, 5);
        students[i].infoGrade = inputInt("Оценка по информатике (2-5): ", 2, 5);
        students[i].physGrade = inputInt("Оценка по физике (2-5): ", 2, 5);
    }
}

void printStudents(Student* students, int count) {
    cout << "\n---------------- СПИСОК СТУДЕНТОВ ----------------\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i].lastName 
             << "\t Матем: " << students[i].mathGrade 
             << "\t Информ: " << students[i].infoGrade 
             << "\t Физика: " << students[i].physGrade << endl;
    }
    cout << "--------------------------------------------------\n";
}

void printExcellentStudents(Student* students, int count) {
    cout << "\n---------------- СПИСОК ОТЛИЧНИКОВ ----------------\n";
    int excellentCount = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].mathGrade == 5 && students[i].infoGrade == 5 && students[i].physGrade == 5) {
            cout << "- " << students[i].lastName << endl;
            excellentCount++;
        }
    }

    cout << "\nВсего отличников: " << excellentCount << endl;
    cout << "--------------------------------------------------\n";
}
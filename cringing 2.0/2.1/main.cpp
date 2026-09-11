#include "base.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

cout << "=== Программа учета отличников ===" << endl;

    int count = inputInt("Введите количество студентов (от 1 до 6): ", 1, 6);
    Student* students = new Student[count];
    cout << "\nВведите оценки для студентов из списка:" << endl;
    inputGradesManual(students, count);
    printStudents(students, count);
    printExcellentStudents(students, count);
    delete[] students;

    return 0;
}
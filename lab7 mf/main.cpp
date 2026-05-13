#include "baza.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    const string f1_stats = "data_stats.txt";
    const string f2_stats = "result_stats.txt";
    const string f1_stud = "data_students.txt";
    const string f2_stud = "result_students.txt";

    cout << " Задание 1 (Статистика) \n";
    createStatsFile(f1_stats);
    
    cout << "\n Задание 2 (Студенты) \n";
    createStudentFile(f1_stud);

    if (isFileValid(f1_stats)) {
        processWebsiteStats(f1_stats, f2_stats);
        cout << "Статистика  в " << f2_stats << endl;
    }

    if (isFileValid(f1_stud)) {
        processStudentList(f1_stud, f2_stud);
        cout << "Список студентов  в " << f2_stud << endl;
    }

    return 0;
}
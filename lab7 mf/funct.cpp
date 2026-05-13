#include "baza.h"

bool isFileValid(const string& filename) {
    ifstream file(filename, ios::ate);
    if (!file.is_open()) {
        cout << "Файл " << filename << " не найден!" << endl;
        return false;
    }
    if (file.tellg() == 0) {
        cout << "Файл " << filename << " пуст!" << endl;
        file.close();
        return false;
    }
    file.close();
    return true;
}


void createStatsFile(const string& filename) {
    ofstream out(filename);
    int n;
    cout << "Введите кол-во записей для статистики: ";
    
    // Проверка корректного ввода числа записей
    while (!(cin >> n) || n <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    cin.ignore();

    cout << "Введите информацию в формате (IP Время День), например: 192.168.1.1 12:00 понедельник\n";
    
    for (int i = 0; i < n; i++) {
        string line;
        string ip, time, day;
        bool isValid = false;

        while (!isValid) {
            cout << "Запись [" << i + 1 << "]: ";
            getline(cin, line);
            
            stringstream ss(line);
            // Пытаемся считать ровно 3 слова. 
            // Если слов меньше или после 3-го слова есть лишние данные — просим переввести.
            if (ss >> ip >> time >> day) {
                string extra;
                if (!(ss >> extra)) { // Проверка, что лишних слов нет
                    out << ip << " " << time << " " << day << endl;
                    isValid = true;
                } else {
                    cout << "Ошибка! Слишком много данных. Введите ровно 3 параметра.\n";
                }
            } else {
                cout << "Ошибка! Нужно ввести 3 параметра (IP Время День). Вы ввели: \"" << line << "\"\n";
            }
        }
    }
    out.close();
}

void createStudentFile(const string& filename) {
    ofstream out(filename);
    int n;
    cout << "Введите кол-во студентов: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string fio;
        cout << "Введите ФИО студента " << i + 1 << ": ";
        getline(cin, fio);
        out << fio << endl;
    }
    out.close();
}


void processWebsiteStats(const string& input, const string& output) {
    ifstream in(input);
    ofstream out(output);

    const int MAX = 200;
    Visit history[MAX];
    int count = 0;

    string line;
    // Читаем файл построчно, чтобы нажатие Enter (пустая строка) не ломало логику
    while (getline(in, line) && count < MAX) {
        if (line.empty()) continue;

        stringstream ss(line);
        string ip, time, day;

        // Проверяем, что в строке действительно есть все три элемента
        if (!(ss >> ip >> time >> day)) {
            continue; // Если данных в строке меньше трех, пропускаем её
        }

        bool duplicate = false;
        for (int i = 0; i < count; i++) {
            if (history[i].ip == ip && history[i].time == time && history[i].day == day) {
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            history[count].ip = ip;
            history[count].time = time;
            history[count].day = day;
            count++;
        }
    }

    // Подсчет и запись результатов (остается без изменений)
    bool viewed[MAX] = {false};
    for (int i = 0; i < count; i++) {
        if (viewed[i]) continue;
        
        int visits = 1;
        for (int j = i + 1; j < count; j++) {
            if (history[i].ip == history[j].ip) {
                visits++;
                viewed[j] = true;
            }
        }
        out << "ip " << history[i].ip << " – " << visits << " посещения за неделю" << endl;
    }

    in.close(); 
    out.close();
}

void processStudentList(const string& input, const string& output) {
    ifstream in(input);
    ofstream out(output);

    string fullLine;
    int id = 1;

    while (getline(in, fullLine)) {
        if (fullLine.empty()) continue; 
        out << id << ". " << fullLine << endl;
        id++;
    }
    in.close(); out.close();
}
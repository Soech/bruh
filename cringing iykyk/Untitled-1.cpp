#include <iostream>
#include <windows.h>
using namespace std;

int zadanie1(){
srand(time(0));
int array[10];
int* pointer = array;
int* lastpointer = array + 9;
for (int i = 0; i < 10; i++){
    *(pointer + i) = rand() % 101;
}
for (int num : array) {
  cout << num << " ";
}
    cout << "Первый массив: " << endl;

for (int i = 0; i < 10; i++){
    if (*pointer % 2 == 0){
        cout << "Chetnie: " << *pointer << ", " << "Индекс [" << i << "]" << "\n";
    }
    pointer++;
}
for (int i = 0; i < 10; i++) {
    if (!(*lastpointer % 2 == 0)) {
        cout << "Nechet: " << *lastpointer << ", " << "Индекс [" << i << "]" << "\n";
    }
    lastpointer--;
}
return 0;
}
int zadanie2(){
    bool findzero = false;
    int array2[10];
    int* point = array2;
    srand(time(0));
    for (int i = 0; i < 10; i++){
        *(point + i) = rand() % 21;  
    }
    for (int num1 : array2) {
    cout << num1 << " ";
}
    cout << "Второй массив: " << endl;
    
    for (int i = 0; i < 10; i++){
        if (*point == 0){
            cout << "Нулевые значения: " << *point << ", " << "Индекс [" << i << "]" << endl;
            findzero = true;
        }
        point++;
    }
        if (!findzero){
        cout << "Нулевой элемент не найден!" << endl;
        }
    return 0;
    }


int main(){
    SetConsoleOutputCP(CP_UTF8);
    zadanie1();
    zadanie2();
}

#include "baza.h"

int proverka(){
    int value;
    while (true){
    if (cin >> value && value >=0)
    return value;
    cout << "Ощибка! Введите целое число:";
    cin.clear();
    cin.ignore(1000, '\n');
    }
}

Movies* createArray(int n){return new Movies[n];}

void fillin(Movies* list, int n){
    for (int i = 0; i < n; i++){
        cout << "\nФильм " << i + 1 << endl;
        cin.ignore(1000, '\n');
        cout << "Название: "; getline(cin, list[i].title);
        cout << "Режиссер: "; getline(cin, list[i].producer);
        cout << "Цена: "; list[i].price = proverka();
    }
}

void PrintSortedMovies(Movies* list, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i; j++){
            if (list[j].price > list[j+i].price) swap(list[j], list[j+1]);
        }
    }
    cout << "\n Список по цене \n" << endl;
    for (int i = 0; i < n- 1; i++){
        cout << list[i].title <<" | Цена: " << list[i].price << endl;
    }
}
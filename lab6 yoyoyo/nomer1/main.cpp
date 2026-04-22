#include "baza.h"

int main(){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Количество фильмов: ";
    int n = proverka();
    Movies* list = createArray(n);
    fillin(list, n);
    PrintSortedMovies(list, n);
    delete[] list;
    return 0;
}
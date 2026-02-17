#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
using namespace std;

void funct()
{
    int v = 15;
    float f = 0.1;
    float g = 9.81;
    int a = 0;
    for (a; a<= 60; a = a + 10)
    {
        float s = pow(v, 2) / (2*g)*(f*cos(a) + sin(a));
        cout << s << endl;
    }
    cout << endl;
}

void funct2()
{
    SetConsoleOutputCP(CP_UTF8);
    int N;
    cout << "Введите натуральное чисто N: ";
    cin >> N;
    float sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum = sum + (1 + (1/pow(i, 2)));
        cout << sum << endl;
    }
}

float calculateZ(float x)
{
    if (x < 0)
        return x * x; 
    else if (x > 0 && x <= 1)
        return sin(x);
    else 
        return cos(x);
}

void funct3()
{
    float x0, x1, dx;
    cout << "Введите x0: ";
    while (!(cin >> x0))
    {
        cout << "Неправильный ввод. Введите число для x0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Введите x1: ";
    while (!(cin >> x1))
    {
        cout << "Неправильный ввод. Введите число для x1: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Введите dx: ";
    while (!(cin >> dx))
    {
        cout << "Неправильный ввод. Введите число для dx: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    int count = 0;
    for (float x = x0; x <= x1; x += dx)
    {
        float z = calculateZ(x);
        cout << x << "\t\t" << z << endl;
    }
}
   



int main()
{
    funct();
    funct2();
    funct3();
}
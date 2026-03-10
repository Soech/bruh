#include <iostream>
#include <cmath>
using namespace std;

float zadanie1(float a, float z)
{
    float znamenatel;
    znamenatel = pow(a, 2) + tan(z);
    if (znamenatel > 0) 
    {
    float zcubic, cos_z, result;
    zcubic = pow(z, 3);
    cos_z = cos(zcubic);
    result = pow(cos_z, 2) - z / sqrt(znamenatel);
    return result;
    }
    else
    {
        return NAN;
    }
}

int zadanie2(float x)
{
    if (x < 1) 
    {
        float cubicroot;
        cubicroot = cbrt(5 * pow(x, 2) + 9 * x) + 3 * x;
        if (cubicroot < 0);
        {
            return NAN;
        }
        return cubicroot;
    }
    else if (x >= 1 && x < 4)
    {
        float znamenatel = 2 * pow(x, 3) + exp(-x);
        float chislitel = pow(x, 5) - 2*pow(x, 4) -5;
        float result = chislitel * znamenatel;
        return result;
    }
        else
    {
        return 6 * x + cos(5 * pow(x, 3) + 8);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    float a, z;
    cout << "Input a: ";
    cin >> a;
    cout << "Input z: ";
    cin >> z;
    float result = zadanie1(a, z);
    cout << "Result 1: " << result << endl;
    float x, y, result1;
    cout << "input x: ";
    cin >> x;
    result1 = zadanie2(x);
    cout << "Result 2: " << result1 << endl;
}
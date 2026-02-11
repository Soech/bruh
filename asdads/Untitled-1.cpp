#include <iostream>
#include <cmath>
using namespace std;

float zadanie1(float a, float z)
{
    float znamenatel;
    znamenatel = pow(a, 2) + tan(z);
    float zcubic, cos_z, result;
    zcubic = pow(z, 3);
    cos_z = cos(zcubic);
    result = pow(cos_z, 2) - z / sqrt(znamenatel);
    return result;
}


int zadanie2(float x)
{
    if (x < 1) 
    {
        return cbrt(5 * pow(x, 2) + 9 * x) + 3 * x;
    } 
    else if (x >= 1 && x < 4)
    {
        float znamenatel;
        znamenatel = 2 * pow(x, 3) + exp(-x);
        return (pow(x, 5) - 2 * pow(x, 4) - 5) / znamenatel;
    }
        else
    {
        return 6 * x + cos(5 * pow(x, 3) + 8);
    }
}

int main()
{
    float a, z;
    cout << "Input a: ";
    cin >> a;
    cout << "Input z: ";
    cin >> z;
    float result = zadanie1(a, z);
    cout << "Result 1: " << result << endl;
    float x, y, result1;
    cout << "input: x";
    cin >> x;
    cout << "input: y";
    cin >> y;
    result1 = zadanie2(x);
    cout << "Result 2: " << result1 << endl;
}
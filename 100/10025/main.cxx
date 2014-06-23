#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, C, rad;

    cin >> a >> b >> C;

    rad = C * M_PI / 180;

    cout << fixed << a * b * sin(rad) / 2 << endl;
    cout << fixed << a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad)) << endl;
    cout << fixed << sin(rad) * b;

    return 0;
}

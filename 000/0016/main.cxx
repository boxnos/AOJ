#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char comma;
    double x = 0, y = 0, env = 0;
    for (double d, t; cin >> d >> comma >> t && (d || t);) {
        x += sin(env) * d;
        y += cos(env) * d;
        env += t * M_PI / 180;
    }
    cout << (int) x << endl;
    cout << (int) y << endl;

    return 0;
}

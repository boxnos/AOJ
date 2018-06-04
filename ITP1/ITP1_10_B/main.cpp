#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, C;
    cin >> a >> b >> C;
    double r = C * M_PI / 180;

    cout << fixed << setprecision(8)
        << a * b * sin(r) / 2 << endl
        << a + b + sqrt(a * a + b * b - 2 * a * b * cos(r)) << endl
        << b * sin(r) << endl;

    return 0;
}

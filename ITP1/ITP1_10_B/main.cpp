#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, h, C, r;
    cin >> a >> b >> C;
    r = C * M_PI / 180;
    h = b * sin(r);

    cout << fixed << setprecision(8)
        << a * h / 2 << endl
        << a + b + sqrt(a * a + b * b - 2 * a * b * cos(r)) << endl
        << h << endl;

    return 0;
}

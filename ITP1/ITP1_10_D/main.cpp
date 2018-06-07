#include <iostream>
#include <iomanip>
#include <valarray>
using namespace std;

int main()
{
    int n;
    cin >> n;
    valarray<double> x(n), y(n), d(4);

    for (auto &xi: x) cin >> xi;
    for (auto &yi: y) cin >> yi;

    for (int i = 0; i < 3; i++)
        d[i] = pow(pow(abs(x - y), i + 1).sum(), 1.0 / (i + 1));
    d[3] = abs(x - y).max();

    cout << fixed << setprecision(8);
    for (auto &di: d)
        cout << di << endl;

    return 0;
}

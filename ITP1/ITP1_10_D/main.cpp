#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> x(n), y(n), d(4);

    for (auto &xi: x) cin >> xi;
    for (auto &yi: y) cin >> yi;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++)
            d[i] += pow(abs(x[j] - y[j]), i + 1);
        d[i] = pow(d[i], 1.0 / (i + 1));
    }

    d[3] = DBL_MIN;
    for (int i = 0; i < n; i++)
        d[3] = max(d[3], abs(x[i] - y[i]));

    cout << fixed << setprecision(8);
    for (auto &di: d)
        cout << di << endl;

    return 0;
}

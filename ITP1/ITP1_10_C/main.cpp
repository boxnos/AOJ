#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << fixed << setprecision(8);

    while (cin >> n, n) {
        vector<double> S(n);
        double sum = 0, Sum = 0;
        for (auto &s: S) {
            cin >> s;
            sum += s;
            Sum += s * s;
        }
        cout << sqrt(Sum / n - pow(sum / n, 2)) << endl;
    }

    return 0;
}

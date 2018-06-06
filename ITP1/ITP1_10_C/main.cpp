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
        }
        double m = sum / n;
        for (auto s: S)
            Sum += pow(s - m, 2);

        cout << sqrt(Sum / n) << endl;
    }

    return 0;
}

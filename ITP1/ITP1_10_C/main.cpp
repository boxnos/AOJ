#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << fixed << setprecision(8);
    while (cin >> n, n) {
        double sum = 0, Sum = 0, s;
        for (int i = n; i--;) {
            cin >> s;
            sum += s;
            Sum += s * s;
        }
        cout << sqrt(Sum / n - pow(sum / n, 2)) << endl;
    }

    return 0;
}

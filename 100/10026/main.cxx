#include <iostream>
#include <cmath>
using namespace std;

inline double average(double sum, int n)
{
    return sum / n;
}

int main()
{
    for (int n, m; cin >> n && (m = n);) {
        double sum = 0;
        double sum_2 = 0;
        for (double s; m-- && cin >> s;) {
            sum += s;
            sum_2 += s * s;
        }
        cout << fixed << sqrt(average(sum_2, n) - average(sum, n) * average(sum, n)) << endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

inline double square(double x) { return x * x; }
inline double distance2d(double x1, double y1, double x2, double y2)
{
    return sqrt(square(x1 - x2) + square(y1 - y2));
}

int main()
{
    for (double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;)
        cout << fixed << distance2d(x1, y1, x2, y2) << endl;

    return 0;
}

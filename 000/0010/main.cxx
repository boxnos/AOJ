#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

inline double square(double x) { return x * x;}
inline double distance2d(double x1, double y1, double x2, double y2)
{
    return sqrt(square(x1 - x2) + square(y1 - y2));
}
int main()
{
    int n;

    cin >> n;
    for (double x1, y1, x2, y2, x3, y3; n-- && cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;) {
        // r
        double d1 = distance2d(x1, y1, x2, y2);
        double d2 = distance2d(x2, y2, x3, y3);
        double d3 = distance2d(x3, y3, x1, y1);

        double r = d1 * d2 * d3 / sqrt((d1 + d2 + d3) *
                                       (-d1 + d2 + d3) *
                                       ( d1 - d2 + d3) *
                                       ( d1 + d2 - d3));

        // positions
        double d = 2 * (x1 * (y2 - y3) + x2 *(y3 - y1) + x3 * (y1 - y2));
        double px = ((x1 * x1 + y1 * y1) * (y2 - y3) +
                     (x2 * x2 + y2 * y2) * (y3 - y1) +
                     (x3 * x3 + y3 * y3) * (y1 - y2))/ d;
        double py = ((x1 * x1 + y1 * y1) * (x3 - x2) +
                     (x2 * x2 + y2 * y2) * (x1 - x3) +
                     (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

        cout << fixed << setprecision(3) << px << " " << py << " " << r << endl;
    }

    return 0;
}

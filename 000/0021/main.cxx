#include <iostream>
#include <limits>
using namespace std;

struct Point2D {
    float x, y;

    Point2D() {}
    Point2D(float ax, float ay) {
        x = ax;
        y = ay;
    }
    Point2D operator -(Point2D &p) {
        return Point2D(x - p.x, y - p.y);
    }
    double slope(Point2D &p) {
        return (p.x != x) ? (p.y - y) / (p.x - x) : numeric_limits<float>::infinity();
    }
    double cross(Point2D &p) { // only z
        return x * p.y - y * p.x;
    }
};

namespace std {
    istream &operator>>(istream &is, Point2D &p) {
        is >> p.x >> p.y;
        return is;
    }

    ostream &operator<<(ostream &os, Point2D &p) {
        os << fixed << p.x << " " << p.y;
        return os;
    }
}

int main()
{
    int n;
    cin >> n;
    for (Point2D a, b, c, d; n-- && cin >> a >> b >> c >> d;)
        cout << ((a.slope(b) == c.slope(d)) ? "YES" : "NO") << endl;

    return 0;
}

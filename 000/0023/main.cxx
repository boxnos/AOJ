#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

struct Point2D {
    float x, y;

    Point2D() {}
    Point2D(float ax, float ay) {
        x = ax;
        y = ay;
    }
    Point2D operator -(const Point2D &p) const {
        return Point2D(x - p.x, y - p.y);
    }
    double distance(const Point2D &p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
    double slope(Point2D &p) {
        return (p.x != x) ? (p.y - y) / (p.x - x) : numeric_limits<float>::infinity();
    }
    double cross(Point2D &p) { // only z
        return x * p.y - y * p.x;
    }
};

istream &operator>>(istream &is, Point2D &p) {
    is >> p.x >> p.y;
    return is;
}

ostream &operator<<(ostream &os, Point2D &p) {
    os << fixed << p.x << " " << p.y;
    return os;
}

int circles_intersection(double distance, double ra, double rb)
{
    if (distance > ra + rb)
        return 0;
    else if (distance >= abs(ra - rb))
        return 1;
    else if (ra > rb)
        return 2;
    else
        return -2;
}

int main()
{
    Point2D pa, pb;
    double ra, rb;

    int n;
    cin >> n;

    for (;n-- && cin >> pa >> ra >> pb >> rb;)
        cout << circles_intersection(pa.distance(pb), ra, rb) << endl;

    return 0;
}

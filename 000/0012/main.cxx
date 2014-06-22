#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;

struct Point2D {
    double x, y;

    Point2D() {}
    Point2D(double ax, double ay) {
        x = ax;
        y = ay;
    }
    Point2D operator -(Point2D &p) {
        return Point2D(x - p.x, y - p.y);
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

    template <typename T>
    ostream &operator<<(ostream &os, vector<T> &v) {
        if (v.size()) {
            cout << v.front();
            for (auto vi = v.begin() + 1; vi != v.end(); vi++)
                cout << " " << *vi;
        }

        return os;
    }
}

template <typename T>
inline int sign(T x) { return (x > T(0)) - (x < T(0)); }

int main()
{
    vector<Point2D> triangle(3);
    Point2D p;

    for (; cin >> triangle[0] >> triangle[1] >> triangle[2] >> p;) {
        int acc = 0;
        for (int i = 0; i < 3; i++) {
            Point2D v = triangle[i] - triangle[(i + 1) % 3];
            Point2D pv = triangle[i] - p;

            acc += sign(v.cross(pv));
        }
        cout << ((abs(acc) == 3) ? "YES" : "NO") << endl;
    }

    return 0;
}

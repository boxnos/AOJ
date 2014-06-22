#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct Point2D {
    double x, y;
};

istream &operator>>(istream &is, Point2D &p)
{
    is >> p.x >> p.y;
    return is;
}

ostream &operator<<(ostream &os, Point2D &p)
{
    os << fixed << p.x << " " << p.y;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    if (v.size()) {
        cout << v.front();
        for (auto vi = v.begin() + 1; vi != v.end(); vi++)
            cout << " " << *vi;
    }

    return os;
}

int main()
{
    vector<Point2D> triangle(3);
    Point2D p;

    for (; cin >> triangle[0] >> triangle[1] >> triangle[2] >> p;)
        cout << triangle << " " << p << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct Point2D {
    double x, y;
};

istream &operator>>(istream &is, Point2D &p)
{
    is >> p.x >> p.y;
    return is;
}

int main()
{
    for (vector<Point2D> p(2); cin >> p[0] >> p[1];)
        cout << endl;

    return 0;
}

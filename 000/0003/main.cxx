#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int square(int x) {
    return x * x;
}

bool is_right_triangle(vector<int> sides)
{
    sort(sides.begin(), sides.end());
    return square(sides[0]) + square(sides[1]) == square(sides[2]);
}

int main()
{
    int length;
    cin >> length;

    for (vector<int> sides(3); length-- && cin >> sides[0] >> sides[1] >> sides[2];)
        cout << (is_right_triangle(sides) ? "YES" : "NO") << endl;

    return 0;
}

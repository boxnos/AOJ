#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    double max_value = 0, min_value = numeric_limits<double>::max();
    for (double h; cin >> h;) {
        min_value = min(h, min_value);
        max_value = max(h, max_value);
    }

    cout << fixed << max_value - min_value << endl;

    return 0;
}

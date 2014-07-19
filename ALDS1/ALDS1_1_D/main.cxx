#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_profit = numeric_limits<int>::min();
    int min_value = numeric_limits<int>::max();

    for (int x; n-- && cin >> x;) {
        max_profit = max(x - min_value, max_profit);
        min_value = min(x, min_value);
    }

    cout << max_profit << endl;

    return 0;
}

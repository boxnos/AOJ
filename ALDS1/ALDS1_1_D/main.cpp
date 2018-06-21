#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    int max_profit = numeric_limits<int>::min();
    int min_value = numeric_limits<int>::max();

    for (int x; cin >> x;) {
        int p = x - min_value;
        if (max_profit < p)
            max_profit = p;
        if (x < min_value)
            min_value = x;
    }

    cout << max_profit << endl;

    return 0;
}

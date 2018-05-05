#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    int n;
    long a;
    long max_value = LONG_MIN;
    long min_value = LONG_MAX;
    long sum = 0;

    cin >> n;

    for (int i = 0; i < n && cin >> a; i++) {
        sum += a;
        max_value = max(max_value, a);
        min_value = min(min_value, a);
    }

    cout << min_value << " " << max_value << " " << sum << endl;

    return 0;
}

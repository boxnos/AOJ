#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n && n != 0) {
        int s;
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n && cin >> s; i++) {
            max_value = max(max_value, s);
            min_value = min(min_value, s);
            sum += s;
        }
        cout << (sum - max_value - min_value) / (n - 2) << endl;
    }
}

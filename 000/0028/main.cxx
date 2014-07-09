#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int size = 101;
    vector<int> numbers(size, 0);
    vector<int> result;
    int max = 0;

    for (int n; cin >> n;) {
        numbers[n]++;
        if (numbers[n] == max)
            result.push_back(n);
        else if (numbers[n] > max) {
            max = numbers[n];
            result.clear();
            result.push_back(n);
        }
    }

    sort(result.begin(), result.end());

    for (int n: result)
        cout << n << endl;

    return 0;
}

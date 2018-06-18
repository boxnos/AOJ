#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, c = 0, m = 0, counter = 0;
    cin >> n;
    vector<int> d(n);
    for (int &x : d) {
        cin >> x;
        m = max(m, x);
    }

    vector<bool> p(m / 2 + 1, true);
    for (int i = 3, e = sqrt(m); i <= e; i += 2) {
        if (!p[i / 2])
            continue;
        for (int j = i * i / 2; j <= m / 2; j += i) {
            p[j] = false;
            counter++;
        }
    }

    for (int x: d)
        if (x == 2 || (x % 2 && p[x / 2]))
            c++;

    cout << c << endl;

    cerr << counter << endl;

    return 0;
}

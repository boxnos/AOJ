#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int n, b, f, r, v;
    vector<vector<vector <int>>> buildings(4, vector<vector <int>>(3, vector<int>(10, 0)));

    cin >> n;
    while (cin >> b >> f >> r >> v && n--)
        buildings[b - 1][f - 1][r - 1] += v;

    for (auto &x : buildings) {
        if (&x != &buildings[0])
            cout << string(20, '#') << endl;
        for (auto y: x) {
            for (auto z : y)
                cout << " " << z;
            cout << endl;
        }
    }

    return 0;
}

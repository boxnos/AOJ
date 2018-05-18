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

    for (int i = 0; i < buildings.size(); i++) {
        if (i)
            cout << string(20, '#') << endl;
        for (auto y: buildings[i]) {
            for (auto z : y)
                cout << " " << z;
            cout << endl;
        }
    }

    return 0;
}

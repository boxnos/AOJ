#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int n, b, f, r, v;

    vector<vector<vector <int>>> buildings
        = vector<vector <vector <int>>>(4, vector<vector <int>>(3, vector<int>(10, 0)));

    cin >> n;
    while (cin >> b >> f >> r >> v && n--)
        buildings[b - 1][f - 1][r - 1] += v;

    for (int i = 0; i < 4; i++) {
        if (i)
            cout << string(20, '#') << endl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++)
                cout << " " << buildings[i][j][k];
            cout << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> b(m);
    vector<vector <int>> A(n, vector<int>(m));

    for (auto &i : A)
        for (auto &j : i)
            cin >> j;

    for (auto &j : b)
        cin >> j;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += A[i][j] * b[j];
        cout << sum << endl;
    }

    return 0;
}

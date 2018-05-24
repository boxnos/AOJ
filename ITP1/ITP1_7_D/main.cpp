#include <iostream>
#include <vector>
using namespace std;

static inline vector<vector<int>> read(vector<vector<int>> v)
{
    for (auto &x: v)
        for (int &y : x)
            cin >> y;
    return move(v);
}

int main(void)
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(m, vector<int>(l));
    a = read(move(a));
    b = read(move(b));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            long sum = 0;
            for (long k = 0; k < m; k++)
                sum += a[i][k] * b[k][j];
            if (j)
                cout << " ";
            cout << sum;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

#define times(n, bind) for (int bind = 0; bind < n; bind++)

inline bool is_edge(int &H, int &W, int &x, int &y)
{
    return x == 0 || y == 0 || x == W - 1 || y == H - 1;
}

int main()
{
    for (int H, W; cin >> H >> W && H && W;) {
        times(H, i) {
            times(W, j)
                cout << (is_edge(H, W, j, i)? '#' : '.');
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

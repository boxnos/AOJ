#include <iostream>
using namespace std;

#define times(n, bind) for (int bind = 0; bind < n; bind++)

inline bool is_black(int &x, int &y)
{
    return (x & 1) == (y & 1);
}

int main()
{
    for (int H, W; cin >> H >> W && H && W;) {
        times(H, i) {
            times(W, j)
                cout << (is_black(j, i)? '#' : '.');
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

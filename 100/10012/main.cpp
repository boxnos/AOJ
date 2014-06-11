#include <iostream>
using namespace std;

#define times(n, bind) for (int bind = 0; bind < n; bind++)

int main()
{
    for (int H, W; cin >> H >> W && H && W;) {
        times(H, i) {
            times(W, j)
                cout << '#';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

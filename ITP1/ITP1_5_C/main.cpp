#include <iostream>
using namespace std;

int main()
{
    int H, W;

    while (cin >> H >> W && H && W) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++)
                cout << (((i + j) % 2)? '.' : '#');
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int H, W;
    bool first = true;

    while (cin >> H >> W && H && W) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++)
                cout << "#";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

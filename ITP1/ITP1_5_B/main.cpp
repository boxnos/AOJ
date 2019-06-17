#include <iostream>
using namespace std;

int main() {
    for (int H, W; cin >> H >> W, W;) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++)
                cout << (i != H - 1 && j != W - 1 && i && j ? '.' : '#');
            cout << endl;
        }
        cout << endl;
    }
}

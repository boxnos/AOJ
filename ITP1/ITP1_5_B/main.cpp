#include <iostream>
#include <string>
using namespace std;

int main()
{
    int H, W;

    while (cin >> H >> W && H && W) {
        cout << string(W, '#') << endl;
        for (int i = 2; i < H; i++)
            cout << '#' << string(W - 2, '.') << '#' << endl;
        cout << string(W, '#') << endl;
        cout << endl;
    }

    return 0;
}

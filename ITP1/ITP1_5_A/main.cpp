#include <iostream>
#include <string>
using namespace std;

int main()
{
    int H, W;

    while (cin >> H >> W && H && W) {
        for (int i = 0; i < H; i++)
           cout << string(W, '#') << endl;
        cout << endl;
    }

    return 0;
}

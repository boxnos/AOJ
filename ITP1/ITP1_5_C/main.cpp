#include <iostream>
#include <string>
using namespace std;

string s(151, '#');

void make_buffer(int w) {
    static int si = 1;
    w += 1;
    for (;si < w; si += 2)
        s[si] = '.';
}

int main()
{
    int H, W;

    while (cin >> H >> W && H && W) {
        make_buffer(W);
        for (int i = 0; i < H; i++)
            cout << s.substr(i & 1, W) << endl;
        cout << endl;
    }

    return 0;
}

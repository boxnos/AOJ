#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string t, h;
    int n, tp = 0, hp = 0;

    cin >> n;

    while (n-- && cin >> t >> h) {
        int i = 0;
        for (int m = min(t.size(), h.size()); i < m && t[i] == h[i]; i++)
            ;
        if (t[i] == h[i])
            tp++, hp++;
        else if (t[i] > h[i])
            tp += 3;
        else
            hp += 3;
    }

    cout << tp << " " << hp << endl;

    return 0;
}

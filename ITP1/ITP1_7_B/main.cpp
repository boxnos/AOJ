#include <iostream>
using namespace std;

int combination(int n, int r, int x)
{
    if (r == 1)
        return (n >= x) ? 1 : 0;

    int count = 0;
    for (int i = n; i > 0; i--)
        if (x - i > 0)
            count += combination(i - 1, r - 1, x - i);

    return count;
}

int main(void)
{
    int n, x;

    while (cin >> n >> x && n || x)
        cout << combination(n, 3, x) << endl;

    return 0;
}

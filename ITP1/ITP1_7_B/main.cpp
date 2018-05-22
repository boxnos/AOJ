#include <iostream>
using namespace std;

int combination(int n, int r, int x){
    if (!r)
        return x ? 0 : 1;
    else if (x <= 0)
        return 0;

    int count = 0;
    for (int i = n; i; i--)
        count += combination(i - 1, r - 1, x - i);

    return count;
}

int main(void)
{
    int n, x;

    while (cin >> n >> x && !(n == 0 && x == 0))
        cout << combination(n, 3, x) << endl;

    return 0;
}

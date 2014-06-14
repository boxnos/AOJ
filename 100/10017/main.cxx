#include <iostream>
#include <vector>
using namespace std;

int how_many_ways(int n, int x, int length, int start)
{
    if (length == 0)
        return (x == 0) ? 1 : 0;
    else if (start > x)
        return 0;

    int count = 0;

    for (int i = start; i <= n; i++)
        count += how_many_ways(n, x - i, length - 1, i + 1);

    return count;
}

int main()
{
    for (int n, x; cin >> n >> x && (n || x);)
        cout << how_many_ways(n, x, 3, 1) << endl;

    return 0;
}

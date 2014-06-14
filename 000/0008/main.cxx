#include <iostream>
using namespace std;

/*
inline int factorial(int n)
{
    int x = 1;
    for (;n != 0; n--)
        x *= n;
    return x;
}

inline int factorial(int s, int n)
{
    int x = 1;
    for (;n > s; n--)
        x *= n;
    return x;
}

inline int conbination(int n, int r)
{
    return factorial(n - r, n) / factorial(r);
}

inline int homogeneous(int n, int r)
{
    return conbination(n + r - 1, r);
}
*/

int count_conbination(int n, int k)
{
    int count = 0;

    if (k == 1)
        if (n <= 9)
            return 1;
        else
            return 0;

    for (int i = 0; i <= 9; i++) {
        int rest = n - i;
        if (rest < 0)
            break;
        else
            count += count_conbination(rest, k - 1);
    }

    return count;
}

int main()
{
    for (int n; cin >> n;)
        cout << count_conbination(n, 4) << endl;

    return 0;
}

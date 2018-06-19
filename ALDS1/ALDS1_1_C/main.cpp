#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> sieve;

void make_sieve(int m) {
    const int l = m / 2 + 1;
    vector<bool> s(l, true);
    for (int i = 3, e = sqrt(m); i <= e; i += 2) {
        if (!s[i / 2])
            continue;
        for (int j = i * i / 2; j < l; j += i)
            s[j] = false;
    }
    for (int i = 1; i < l; i++)
        if (s[i])
            sieve.push_back(i * 2 + 1);
}

bool is_prime(int x)
{
    if (x == 2)
        return true;
    else if (x % 2 == 0)
        return false;

    const int e = sqrt(x);
    for (int p : sieve)
        if (p > e)
            return true;
        else if (x % p == 0)
            return false;

    return true;
}

int main()
{
    int n, c = 0, m = 0;
    cin >> n;
    vector<int> d(n);
    for (int &x: d) {
        cin >> x;
        m = max(m, x);
    }

    make_sieve(sqrt(m));

    for (int x: d)
        if (is_prime(x))
            c++;

    cout << c << endl;
}

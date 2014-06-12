#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

void sieve(int n, list<int> &primes)
{
    vector<bool> v(n / 2 + 1, true);

    // check
    for (int i = 3, end = sqrt(n); i <= end; i += 2) {
        if (!v[i / 2])
            continue;
        for (int j = i * i / 2; j <= n / 2; j += i)
            v[j] = false;
    }

    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
         if (v[i / 2])
            primes.push_back(i);
}

int main()
{
    list<int> primes;
    vector<int> inputs;

    // read all inputs
    for (int x; cin >> x;)
        inputs.push_back(x);

    // init sieve
    sieve(*max_element(inputs.begin(), inputs.end()), primes);

    for (auto x : inputs) {
        int count = 0;
        for (auto p : primes) // find
            if (p == x) {
                count++;
                break;
            } else if (p > x)
                break;
            else
                count++;
        cout << count << endl;
    }

    return 0;
}

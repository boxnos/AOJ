#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void sieve(int n, vector<int> &primes)
{
    vector<bool> v(n + 1, true);

    // check
    for (int i = 2, end = sqrt(n); i <= end; i++) {
        if (!i)
            continue;
        for (int j = i + i; j <= n; j += i)
            v[j] = false;
    }

    for (int i = 2; i <= n; i++)
         if (v[i])
            primes.push_back(i);
}

int main()
{
    vector<int> primes;
    vector<int> inputs;
    int i;

    // read all inputs
    for (int x; cin >> x;)
        inputs.push_back(x);

    // init sieve
    sieve(*max_element(inputs.begin(), inputs.end()), primes);

    for (auto x : inputs) {
        for (i = 0; i < primes.size(); i++) // find
            if (primes[i] == x) {
                i++;
                break;
            } else if (primes[i] > x)
                break;
        cout << i << endl;
    }

    return 0;
}

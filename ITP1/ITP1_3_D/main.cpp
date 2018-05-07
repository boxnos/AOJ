#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

vector<int> divisors;
void make_divisors(map<int, int>::iterator begin, map<int, int>::iterator end, int product) {
    if (begin == end)
        divisors.push_back(product);
    else
        for (int i = 0; i <= begin->second; i++)
            make_divisors(std::next(begin), end, product * pow(begin->first, i));
}

int main(void)
{
    int a, b, c;
    int cnt = 0;
    map<int, int> factors;

    cin >> a >> b >> c;

    for (int i = 2, e = c; e != 1 || i <= sqrt(c); i++)
        while (e % i == 0) {
            e /= i;
            if (factors.count(i))
                factors[i]++;
            else
                factors.insert(pair<int, int>(i, 1));
        }

    make_divisors(factors.begin(), factors.end(), 1);

    for (int i = 0; i < divisors.size(); i++)
        if (a <= divisors[i] && divisors[i] <= b)
            cnt++;

    cout << cnt << endl;
}

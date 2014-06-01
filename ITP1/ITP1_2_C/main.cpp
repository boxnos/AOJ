#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <sstream>
using namespace std;

template <typename T>
string join(vector<T> &v, const string &delimiter)
{
    stringstream buffer;
    if (v.size() > 0) {
        buffer << v[0];
        for (auto it = v.begin() + 1; it != v.end(); it++)
            buffer << delimiter << *it;
    }
    return buffer.str();
}

int main()
{
    vector<int> v;
    int x;

    while (cin >> x)
        v.push_back(x);

    sort(v.begin(), v.end(), [](int a, int b) {return a < b;});

    cout << join(v, " ") << endl;

    return 0;
}

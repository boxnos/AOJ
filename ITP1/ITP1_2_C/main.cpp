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
    for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
        if (it != v.begin())
            buffer << delimiter;
        buffer << *it;
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

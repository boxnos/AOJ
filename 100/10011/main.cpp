#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

#define all(bind) bind.begin(), bind.end()

template <typename T>
string join(vector<T> &v, const string &delimiter)
{
    stringstream buffer;
    if (v.size() > 0) {
        buffer << v[0];
        for (typename vector<T>::iterator it = v.begin() + 1; it != v.end(); it++)
            buffer << delimiter << *it;
    }
    return buffer.str();
}

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    for (int buffer; cin >> buffer && n; n--)
        a.insert(a.begin(), buffer);

    cout << join(a, " ") << endl;

    return 0;
}

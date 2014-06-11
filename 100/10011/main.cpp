#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

#define all(bind) bind.begin(), bind.end()

template <typename T>
string join(T &v, const string &delimiter)
{
    stringstream buffer;
    if (v.size() > 0) {
        buffer << v.front();
        for (typename T::iterator it = ++(v.begin()); it != v.end(); it++)
            buffer << delimiter << *it;
    }
    return buffer.str();
}

int main()
{
    int n;
    list<int> a;

    cin >> n;
    for (int buffer; cin >> buffer && n; n--)
        a.push_front(buffer);

    cout << join(a, " ") << endl;

    return 0;
}

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, set<T> &s) {
    if (s.size()) {
        auto si = s.begin();
        os << *si;
        for (si++; si != s.end(); si++)
            os << " " << *si;
    }
    return os;
}

int main()
{
    set<int> S, T;
    int n, q, count = 0;

    cin >> n;
    for (int x; n-- && cin >> x;)
        S.insert(x);

    cin >> q;
    for (int x; q-- && cin >> x;)
        T.insert(x);

    if (S.size() > T.size())
        swap(S, T);

    for (auto x : S)
        if (T.find(x) != T.end())
            count++;

    cout << count << endl;

    return 0;
}

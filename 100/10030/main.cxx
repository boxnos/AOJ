#include <iostream>
#include <set>
using namespace std;

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

    for (auto x : S)
        if (T.find(x) != T.end())
            count++;

    cout << count << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    if (v.size()) {
        os << v.front();
        for (auto vi = v.begin() + 1; vi != v.end(); vi++)
            os << " " << *vi;
    }
    return os;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());

    cout << data << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template <typename T>
ostream &operator<<(ostream &o,vector<T> &v)
{for(T &x:v)o<<(&x!=&v[0]?" ":"")<<x;return o;}

int main()
{
    vector<int> d = {5, 4, 2, 3, 1, 6};
    bool flag;
    // int n = 0;

    cout << d << endl;
    do  {
        flag = false;
        // cout << endl << "loop : " << ++n << endl;
        for (size_t i = 0; i < d.size() - 1; i++) {
            if (d[i] > d[i + 1]) {
                swap(d[i], d[i + 1]);
                cout << d << endl;
                // cout << string(i * 2, ' ') << "^ ^" << endl;
                flag = true;
            }
        }
    } while (flag);
}

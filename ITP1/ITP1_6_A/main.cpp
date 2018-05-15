#include <iostream>
#include <vector>
using namespace std;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{for(int i=0;i<v.size();i++){if(i>0)o<<" ";o<<v[i];}return o;}

int main(void)
{
    int n;

    cin >> n;
    vector<int> a(n);

    while (n--)
        cin >> a[n];

    cout << a << endl;

    return 0;
}

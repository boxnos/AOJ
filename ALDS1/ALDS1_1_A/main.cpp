#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> ostream &operator<<(ostream &o,vector<T> &v)
{for(T &x:v)o<<(&x!=&v[0]?" ":"")<<x;return o;}

int main()
{
	int n;
	cin >> n;

	vector<int> d(n);
	for (int &x: d)
		cin >> x;

	auto b = d.begin();
	for (int i = 1; i <= n; i++) {
		sort(b, b + i);
		cout << d << endl;
	}
}

/* vim: set ts=4 noet: */

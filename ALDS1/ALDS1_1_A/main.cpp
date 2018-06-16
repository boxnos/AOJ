#include <iostream>
#include <vector>
#include <utility>
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

	cout << d << endl;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0 && d[j] > d[j + 1]; j--)
			swap(d[j], d[j + 1]);
		cout << d << endl;
	}
}

/* vim: set ts=4 noet: */

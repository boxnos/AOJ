#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, c = 0;
	cin >> n;

	vector<int> v(n);
	for (int &x: v)
		cin >> x;

	for (auto i = v.begin(), e = v.end(); i != e - 1; i++) {
		auto min = i, j = i;
		for (; j != e; j++)
			if (*j < *min)
				min = j;
		if (i != min)
			swap(*i, *min), c++;
	}

	for (int &x: v)
		cout << (&x == &v[0] ? "" : " ") << x;
	cout << endl << c << endl;
}

/* vim: set ts=4 noet: */

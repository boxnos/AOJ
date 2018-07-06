#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, q, C = 0;

	cin >> n;
	vector<int> S(n);
	for (int &x: S)
		cin >> x;

	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		auto res = find(S.begin(), S.end(), x);
		if (res != S.end())
			C++;
	}

	cout << C << endl;
}

/* vim: set ts=4 noet: */

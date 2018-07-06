#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	set<int> S;
	int C = 0;

	auto f = [](auto g) {
		int n, x;
		cin >> n;
		while (n--) {
			cin >> x; g(x);
		}
	};

	f([&](int x){S.insert(x);});

	f([&](int x){if(find(S.begin(), S.end(), x) != S.end()) C++;});

	cout << C << endl;
}

/* vim: set ts=4 noet: */

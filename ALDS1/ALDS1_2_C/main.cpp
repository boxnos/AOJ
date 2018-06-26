#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef string s;
typedef vector<s> vs;

void p(vs &v)
{
	for (s &x: v)
		cout << (&x == &v[0] ? "" : " ") << x;
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vs bs(n), ss(n);
	for (s &x: bs)
		cin >> x;
	ss = bs;

	auto cmp = [](s a, s b){return a[1] < b[1];};
	stable_sort(bs.begin(), bs.end(), cmp);
	p(bs);
	cout << "Stable" << endl;

	for (auto i = ss.begin(), e = ss.end(); i != e - 1; i++) {
		auto min = min_element(i ,e, cmp);
		if (i != min)
			swap(*i, *min);
	}
	p(ss);
	cout << (bs == ss ? "Stable" : "Not stable") << endl;
}

/* vim: set ts=4 noet: */

#include <iostream>
#include <set>
#include <unordered_map>
#include <iterator>
using namespace std;

typedef multiset<int> mi;
typedef mi::reverse_iterator ri;
unordered_map<int, bool> memo;

int counter = 0;
bool solve(ri p, int t, mi &A) {
	counter++;
	
	long key = distance(A.rbegin(), p) + 1 + ((t + 1) << 16);
	auto i = memo.find(key);
	if (i != memo.end())
		return (*i).second;

	bool res;
	if (t == 0)
		res = true;
	else if (p == A.rend())
		res = false;
	else if (*p <= t)
		res = solve(next(p, 1), t - *p, A) ? true : solve(next(p, 1), t, A);
	else {
		ri r = make_reverse_iterator(A.upper_bound(t));
		res = solve(r, t - *p, A) ? true : solve(r, t, A);
	}

	memo[key] = res;
	return res;
}

int main()
{
	int n, q, m, sum = 0;

	cin >> n;
	mi A;
	while (n--) {
		cin >> m;
		A.insert(m);
		sum += m;
	}
	
	cin >> q;
	while (q--) {
		cin >> m;
		cout << (m > sum ? "no" : solve(A.rbegin(), m, A) ? "yes" : "no") << endl;
	}

	cerr << counter << endl;
}

/* vim: set ts=4 noet: */

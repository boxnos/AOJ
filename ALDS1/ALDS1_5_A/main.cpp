#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int counter = 0;
bool solve(size_t p, int t, vi &A) {
	counter++;
	if (t == 0)
		return true;
	if (p == A.size())
		return false;

	return solve(p + 1, t - A[p], A) ? true : solve(p + 1, t, A);
}

int main()
{
	int n, q, m;

	cin >> n;
	vi A(n);
	for (int &x: A)
		cin >> x;
	
	cin >> q;
	while (q--) {
		cin >> m;
		cout << (solve(0, m, A) ? "yes" : "no") << endl;
	}

	cerr << counter << endl;
}

/* vim: set ts=4 noet: */

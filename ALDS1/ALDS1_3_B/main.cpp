#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<string, int> ps;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	queue<ps> Q;
	int n, q, st = 0;
	cin >> n >> q;

	ps p;
	while (n--) {
		cin >> p.first >> p.second;
		Q.push(p);
	}

	while (!Q.empty()) {
		ps t = Q.front();
		Q.pop();
		if (t.second <= q) {
			st += t.second;
			cout << t.first << " " << st << endl;
		} else {
			st += q;
			t.second -= q;
			Q.push(t);
		}
	}
}

/* vim: set ts=4 noet: */

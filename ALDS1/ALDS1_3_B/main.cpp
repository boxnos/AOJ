#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair<char[11], int> ps;

int main()
{
	queue<ps> Q;
	int n, q, st = 0;
	scanf("%d %d", &n, &q);

	ps p;
	while (n--) {
		scanf("%s %d", p.first, &p.second);
		Q.push(p);
	}

	while (!Q.empty()) {
		ps t = Q.front();
		Q.pop();
		if (t.second <= q) {
			st += t.second;
			printf("%s %d\n", t.first, st);
		} else {
			st += q;
			t.second -= q;
			Q.push(t);
		}
	}
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

static inline void p(int x) { printf("%d\n", x); }

int main()
{

	int n, cnt = 0;
	scanf("%d", &n);

	vector<int> A(n), G;
	for (int &x: A)
		scanf("%d", &x);

	for (int i = 1, x = 1; x <= n; x = (pow(3, ++i) - 1) / 2)
		G.push_back(x);
	reverse(G.begin(), G.end());

	for (int g: G)
		for (auto i = A.begin() + g; i != A.end(); i++) {
			int v = *i;
			auto j = i - g;
			for(; j >= A.begin() && *j > v; j -= g)
				*(j + g) = *j, cnt++;
			*(j + g) = v;
		}

	p(G.size());
	for (int &x: G)
		printf("%s%d", (&x == &G[0] ? "" : " "), x);
	puts("");
	p(cnt);
	for (int x: A)
		p(x);
}

/* vim: set ts=4 noet: */

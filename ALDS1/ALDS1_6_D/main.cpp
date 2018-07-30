#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> v;

#define gcu getchar_unlocked
static inline int in()
{
	int c, n = 0;
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return n;
}

int cost = 0;
void mcs(v w, v &s, int acc, int c)
{
	if (acc > cost)
		return;
	else if (w == s) {
		cost = min(acc, cost);
		return;
	}

	for (size_t i = 0; i < w.size() - 1; i++) {
		for (size_t j = i + 1; j < w.size(); j++) {
			swap(w[i], w[j]);
			mcs(w, s, acc + w[i] + w[j], c + 1);
			swap(w[i], w[j]);
		}
	}
}

int main()
{
	v w(in());

	for (int &x : w) {
		x = in();
		cost += x * 1.5;
	}
	v s = w;

	sort(s.begin(), s.end());
	mcs(w, s, 0, 0);
	printf("%d\n", cost);
}

/* vim: set ts=4 noet: */

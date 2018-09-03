#include <cstdio>
#include <iostream>
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

int hn(v &w, v &s) {
	int c = 0;
	auto b = s.begin();
	for (int a: w)
		if (a != *b++)
			c += a;
	return c;
}

int mcs(v w, v &s, int g, int h, int limit)
{
	if (g + h > limit)
		return -1;
	if (!h)
		return g;

	for (size_t i = 0; i < w.size() - 1; i++) {
		for (size_t j = i + 1; j < w.size(); j++) {
	//		if (w[i] == s[j] || w[j] == s[i]) {
				swap(w[i], w[j]);
				int res = mcs(w, s, g + w[i] + w[j],
							  h - w[i] - w[j] + (w[i] == s[i] ? 0 : w[i]) + + (w[j] == s[j] ? 0 : w[j]), limit);
				if (res != -1)
					return res;
				swap(w[i], w[j]);
	//		}
		}
	}
	return -1;
}

int main()
{
	v w(in());

	for (int &x : w)
		x = in();
	v s = w;

	sort(s.begin(), s.end());
	//printf("%d\n", hn(w, s));
	int h = hn(w, s), r = -1;
	for (int limit = h; r == -1; limit += 1)
		r = mcs(w, s, 0, h, limit);
	printf("%d\n", r);
}

/* vim: set ts=4 noet: */

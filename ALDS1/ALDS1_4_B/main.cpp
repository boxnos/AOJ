#include <cstdio>
#include <algorithm>
using namespace std;

static inline int in()
{
	int n = 0, c = getchar_unlocked();
	do {
		n = 10 * n + c - '0';
		c = getchar_unlocked();
	} while (c >= '0');
	return n;
}

int main()
{
	int C = 0, n = in(), q;
	int S[n];

	for (int &x: S)
		x = in();

	int *e = S + n;
	q = in();
	while (q--)
		if(binary_search(S, e, in()))
			C++;

	printf("%d\n", C);
}

/* vim: set ts=4 noet: */

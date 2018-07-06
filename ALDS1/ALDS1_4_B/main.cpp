#include <cstdio>
#include <algorithm>
using namespace std;

static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		// n = 10 * n + (c - '0');
		n = (n << 3) + ( n << 1 ) + c - '0';
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

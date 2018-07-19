#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> v;
typedef v::iterator vi;

v b;

long msc(vi l, vi r)
{
	long c = 0;
	if (l + 1 < r) {
		vi m = l + (r - l) / 2;
		c = msc(l, m) + msc(m, r);

		vi bp = b.begin();
		vi bend = bp + (m - l);
		copy(l, m, b.begin());

		vi i = l;
		for (; bp != bend && m != r; i++)
			if(*bp < *m)
				*i = *bp++;
			else
				*i = *m, c += m++ - i;

		copy(bp, bend, i);
	}
	return c;
}

static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
    return n;
}

int main()
{
	int	n = in();

	v a(n);
	b = v(n);

	for (int &x: a)
		x = in();

	printf("%ld\n", msc(a.begin(), a.end()));
}

/* vim: set ts=4 noet: */

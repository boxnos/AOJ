#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> v;
typedef v::iterator vi;

static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
    return n;
}

#define pcu putchar_unlocked
static inline void out(int n)
{
	static char buf[20];
	char *p = buf;
	if (!n)
		*p++ = '0';
	else
		while (n)
			*p++ = n % 10 + '0', n /= 10;
	while (p != buf)
		pcu(*--p);
}

int main()
{
	v A(in());

	for (int &x : A)
		x = in();

	vi x = A.end() - 1, i = A.begin(), j = i;
	for (;j != x;j++)
		if (*j <= *x)
			swap(*j, *i++);
	swap(*i, *x);

	for (int &x : A) {
		if (&x != &A[0])
			pcu(' ');
		if (&x == &*i)
			pcu('['), out(x), pcu(']');
		else
			out(x);
	}
	puts("");
}

/* vim: set ts=4 noet: */

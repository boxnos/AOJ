#include <cstdio>
#include <vector>
using namespace std;

struct card {char f; int n, i;};

typedef vector<card> v;
typedef v::iterator vi;

#define gcu getchar_unlocked
static inline int in()
{
    int c, n = 0;
    while ((c = gcu()) >= '0' && c <= '9')
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

bool qs(vi p, vi r) {
	bool s = true;
	if (p < r) {
		vi i = p, j = i;
		for (;j != r;j++) {
			if ((*j).n == (*r).n && (*j).i > (*r).i)
				s = false;
			if ((*j).n <= (*r).n)
				swap(*j, *i++);
		}
		swap(*i, *r);

		s &= qs(p, i - 1);
		s &= qs(i + 1, r);
	}
	return s;
}

int main()
{
	v A(in());

	int i = 0;
	for (card &x : A) {
		x.f = gcu(), gcu();
		x.n = in();
		x.i = i++;
	}

	puts(qs(A.begin(), A.end() - 1) ? "Stable" : "Not stable");

	for (card &x : A)
		pcu(x.f), pcu(' '), out(x.n), pcu('\n');
}

/* vim: set ts=4 noet: */

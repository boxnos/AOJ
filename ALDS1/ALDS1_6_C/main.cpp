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

void qs(vi p, vi r) {
	if (p < r) {
		vi i = p, j = i;
		card R = *r;
		for (;j != r;j++)
			if ((*j).n <= R.n)
				swap(*j, *i++);
		swap(*i, *r);

		qs(p, i - 1);
		qs(i + 1, r);
	}
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

	vi b = A.begin(), e = A.end();
	qs(b, e - 1);

	bool s = true;
	for (vi i = b + 1; i < e; i++, b++)
		if ((*b).n == (*i).n && (*b).i > (*i).i) {
			s = false;
			break;
		}
	puts(s ? "Stable" : "Not stable");

	for (card &x : A)
		pcu(x.f), pcu(' '), out(x.n), pcu('\n');
}

/* vim: set ts=4 noet: */

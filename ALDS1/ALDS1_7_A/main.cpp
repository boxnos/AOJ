#include <cstdio>
#include <vector>
using namespace std;

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
	bool minus = false;
	if(n < 0)
		minus = true, n *= -1;
	if (!n)
		*p++ = '0';
	else
		while (n)
			*p++ = n % 10 + '0', n /= 10;
	if (minus)
		*p++ = '-';
	while (p != buf)
		pcu(*--p);
}

static inline void out(const char *s) {
	while (*s)
		pcu(*s++);
}

typedef vector<int> v;
typedef v::iterator vi;
struct node { int p = -1, d = -1; v c; };
typedef vector<node> vn;

int depth(vn &n, int id) {
	if (n[id].d > 0)
		return n[id].d;
	else if (n[id].p == -1)
		return 0;
	else {
		int res = 1 + depth(n, n[id].p);
		n[id].d = res;
		return res;
	}
}

int main()
{
	int n = in();
	vn nodes(n);

	while (n--) {
		int id = in();
		nodes[id].c.resize(in());
		for (int &x: nodes[id].c) {
			x = in();
			nodes[x].p = id;
		}
	}

	int id = 0;
	for (node u: nodes) {
		int d = depth(nodes, id);
		out("node ");
		out(id++);
		out(": parent = ");
		out(u.p);
		out(", depth = ");
		out(d);
		out(", ");
		out(d == 0 ? "root" : u.c.size() ? "internal node" : "leaf");
		out(", [");
		for (int &x: u.c) {
			if (&x != &u.c[0])
				out(", ");
			out(x);
		}
		out("]\n");
	}
}

/* vim: set ts=4 noet: */

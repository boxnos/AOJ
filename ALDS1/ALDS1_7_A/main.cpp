#include <cstdio>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	while ((c = gcu()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
	return n; }
#define pcu putchar_unlocked
si void out(int n) {
	static char buf[20];
	char *p = buf;
	bool minus = false;
	if(n < 0) minus = true, n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	if (minus) *p++ = '-';
	while (p != buf) pcu(*--p); }
si void out(const char *s) {
	while (*s) pcu(*s++); }
template <typename head, typename... tail>
si void out(head&& h, tail&&... t) {
	out(h); out(move(t)...); }

typedef vector<int> v;
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
		out("node ", id++, ": parent = ", u.p, ", depth = ", d, ", ",
		   	d == 0 ? "root" : u.c.size() ? "internal node" : "leaf", ", [");
		for (int &x: u.c) {
			if (&x != &u.c[0])
				out(", ");
			out(x);
		}
		out("]\n");
	}
}

/* vim: set ts=4 noet: */

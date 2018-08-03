#include <cstdio>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-')
		minus = true;
	else
		ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
	return minus ? -n : n; }
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
struct node { int p = -1, l = -1, r = -1, d = -1, h = -1;};
typedef vector<node> vn;

int depth(vn &n, int id)
{
	node &i = n[id];
	if (i.d > 0)
		return i.d;
	else if (i.p == -1)
		return 0;
	else {
		int d = 1 + depth(n, i.p);
		i.d = d;
		return d;
	}
}

int height(vn &n, int id)
{
	node &i = n[id];
	if (i.h > -1)
		return i.h;
	else if (i.l == -1 && i.r == -1) {
		i.h = 0;
		return 0;
	}
	i.h = max(i.l == -1 ? 0 : 1 + height(n, i.l),
			  i.r == -1 ? 0 : 1 + height(n, i.r));
	return i.h;
}

int main()
{
	int n = in();
	vn nodes(n);

	while (n--) {
		int id = in();
		node &i = nodes[id];
		i.l = in();
		i.r = in();
		if (i.l >= 0) nodes[i.l].p = id;
		if (i.r >= 0) nodes[i.r].p = id;
	}

	int i = 0;
	for (node &n: nodes) {
		int d = (n.l != -1) + (n.r != - 1);
		out("node ", i, ": parent = ", n.p, ", sibling = ",
			n.p == -1 ? -1 : nodes[n.p].r == i ? nodes[n.p].l : nodes[n.p].r,
			", degree = ", d, ", depth = ", depth(nodes, i), ", height = ", height(nodes, i),
			", ", n.p == -1 ? "root" : d ? "internal node" : "leaf",
			"\n");
		i++;
	}
}

/* vim: set ts=4 noet: */

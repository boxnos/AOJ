#include <cstdio>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true;
	else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
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
si void out(const char *s){while(*s)pcu(*s++);}
si void out(char c){pcu(c);}
template <typename head, typename... tail>
si void out(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;
struct node { int p = -1, l = -1, r = -1;};
typedef vector<node> vn;

#define pb push_back
v buf[3];
void walk(vn &t, int n)
{
	buf[0].pb(n);
	if (t[n].l != -1) walk(t, t[n].l);
	buf[1].pb(n);
	if (t[n].r != -1) walk(t, t[n].r);
	buf[2].pb(n);

}

int main()
{
	int n = in();
	vn tree(n);

	while (n--) {
		int id = in();
		node &i = tree[id];
		i.l = in();
		i.r = in();
		if (i.l >= 0) tree[i.l].p = id;
		if (i.r >= 0) tree[i.r].p = id;
	}

	int root = 0;
	while (tree[root].p != -1)
		root = tree[root].p;
	walk(tree, root);

	const char w[][20] = {"Preorder", "Inorder", "Postorder"};
	for (v &b: buf) {
		out(w[&b - &buf[0]], '\n');
		for(int n: b)
			out(' ', n);
		out('\n');
	}
}

/* vim: set ts=4 noet: */

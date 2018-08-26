#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int n = 0, c = gcu();
	bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	// return n; }
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
svo(int n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
svo(vector<T> &v){for(auto &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo
#undef si

typedef vector<int> v;

struct bst
{
	struct node { int v, l = -1, r = -1; };
	int root = -1, i = 0;
	vector<node> nodes;

	bst(int n)
	{
		nodes.resize(n);
	}

	int insert (int r, int n)
	{
		if (r == -1) {
			nodes[i].v = n;
			r = i++;
		} else if (nodes[r].v < n)
			nodes[r].r = insert(nodes[r].r, n);
		else
			nodes[r].l = insert(nodes[r].l, n);
		return r;
	}
	void insert (int n)
	{
		root = insert(root, n);
	}
	void print(int r, v &buf)
	{
		if (r == -1)
			return;
		node n = nodes[r];
		buf.push_back(n.v);
		print(n.l, buf);
		out(' ', n.v);
		print(n.r, buf);
	}
	void print()
	{
		v buf;
		print(root, buf);
		out('\n'), out(buf);
	}
};

int main()
{
	int n = in();
	char s[20];
	bst b(n);

	while (n--) {
		scan(s);
		if (*s == 'i')
			b.insert(in());
		else
			b.print();
	}
}

/* vim: set ts=4 noet: */

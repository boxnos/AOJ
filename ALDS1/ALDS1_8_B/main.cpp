#include <cstdio>
#include <cctype>
#include <vector>
#include <unordered_set>
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
//svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
svo(vector<T> v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(int &x:v)out(&x == &v[0]?"":" ",x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

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
	bool find(int r, int v)
	{
		if (r == -1)
			return false;
		node &n = nodes[r];
		return n.v == v ? true : n.v < v ? find(n.r, v) : find(n.l, v);
	}
	bool find (int n)
	{
		return find(root, n);
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
		out('\n', buf);
	}
};

int main()
{
	int n = in(), x;
	char s[20];
	bst b(n);
	unordered_set<int> f;

	while (n--) {
		scan(s);
		switch(*s) {
		case 'i':
			x = in();
			b.insert(x);
			f.insert(x);
			break;
		case 'f':
			out(f.count(in()) ? "yes\n": "no\n"); break;
		default:
			b.print();
		}
	}
}

/* vim: set ts=4 noet: */

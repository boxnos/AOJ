#include <cstdio>
#include <cctype>
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

	int insert (int r, int v)
	{
		if (r == -1) {
			nodes[i].v = v;
			return i++;
		}
		node &n = nodes[r];
		if (n.v < v)
			n.r = insert(n.r, v);
		else
			n.l = insert(n.l, v);
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
	bool find(int v)
	{
		return find(root, v);
	}
	int get_and_remove_next_idx(int &r) {
		if (nodes[r].l == -1) {
			int tmp = r;
			r = erace(r, nodes[r].v);
			return tmp;
		}
		return get_and_remove_next_idx(nodes[r].l);
	}
	int erace(int r, int v)
	{
		if (r == -1)
			return -1;
		node &n = nodes[r];
		if (n.v == v)
			if (n.l == -1 && n.r == -1)
				return -1;
			else if (n.l == -1) {
				r = n.r;
				n = nodes[r];
			} else if (n.r == -1) {
				r = n.l;
				n = nodes[r];
			} else {
				int tmp = get_and_remove_next_idx(n.r);
				n.v = nodes[tmp].v;
			}
		else if (n.v < v)
			n.r = erace(n.r, v);
		else
			n.l = erace(n.l, v);
		return r;
	}
	void erace(int v)
	{
		root = erace(root, v);
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
	int n = in();
	char s[20];
	bst b(n);

	while (n--) {
		scan(s);
		switch(*s) {
		case 'i':
			b.insert(in()); break;
		case 'f':
			out(b.find(in()) ? "yes\n": "no\n"); break;
		case 'd':
			b.erace(in()); break;
		default:
			b.print();
		}
	}
}

/* vim: set ts=4 noet: */

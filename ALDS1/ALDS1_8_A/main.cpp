#include <cstdio>
#include <cctype>
#include <vector>
#include <iterator>
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
	bool minus = false;
	if(n < 0) minus = true, n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	if (minus) *p++ = '-';
	while (p != buf) pcu(*--p); }
svo(char *s){while(*s)pcu(*s++);}
svo(const char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
svo(vector<T> v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(int &x:v)out(&x == &v[0]?"":" ",x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;

struct bst
{
#define VNI vector<node>::iterator
	struct node {
		int v;
		VNI l = VNI(), r = VNI();
	};
	typedef vector<node> vn;
	typedef vn::iterator vni;
	vn nodes;
	vni root = vni(), i, vnin = root;

	bst(int n)
	{
		nodes.resize(n);
		i = nodes.begin();
	}

	vni insert (vni r, int n)
	{
		if (r == vnin) {
			(*i).v = n;
			r = i++;
		} else if ((*r).v < n)
			(*r).r = insert((*r).r, n);
		else
			(*r).l = insert((*r).l, n);
		return r;
	}
	void insert (int n)
	{
		root = insert(root, n);
	}
	void print(vni r, v &buf)
	{
		if (r == vnin)
			return;
		node n = *r;
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
		if (*s == 'i')
			b.insert(in());
		else
			b.print();
	}
}

/* vim: set ts=4 noet: */

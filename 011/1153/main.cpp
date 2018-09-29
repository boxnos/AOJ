#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define gcu getchar_unlocked
#define ii inline int in
#define is inline bool scan
ii(int c) {
	int n = 0;
	bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	//return n; }
	return minus ? -n : n; }
ii() {return in(gcu());}
is(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
is(char &c){c=gcu();gcu();return c!=EOF;}
//is(string &s) {int c;for(;;){c=gcu();if(c=='\n'||c==' ')return true;s+=c;}}
#undef ii
#define pcu putchar_unlocked
template <typename T>
void out(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
void out(const char *s){while(*s)pcu(*s++);}
void out(char c){pcu(c);}
//void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

typedef vector<int> v;

struct deck {
	v d;
	int t = 0;

	deck(int n) {
		d = v(n);
		for (int &x: d)
			x = in(), t += x;
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
	}

	v cmp(deck &b, size_t i, size_t j) {
		if (i >= d.size() || j >= b.d.size())
			return {-1};

		int a = d[i], c = b.d[j], diff = (t - a + c) - (b.t - c + a);
		if (!diff)
			return {a, c};
		if (diff > 0)
			return cmp(b, i + 1, j);
		else
			return cmp(b, i, j + 1);
	}
};

int main() {
	int n, m;
	while (n = in(), m = in(), n || m) {
		deck a(n), b(m);
		v r = a.cmp(b, 0, 0);
		out(r);
	}
}

/* vim: set ts=4 noet: */

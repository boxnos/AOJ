#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true; else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
//svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;
struct graph {
	vector<v> nodes;

	graph(int n) {
		nodes.resize(n);
	}
	void read(int n) {
		while (n--) {
			int s = in(), t = in();
			nodes[s].push_back(t);
			nodes[t].push_back(s);
		}
	}
	bool find(int s, int t, v &f) {
		if (s == t)
			return true;
		f[s] = 1;
		for (int x: nodes[s])
			if (!f[x] && find(x, t, f))
				return true;
		return false;
	}
	bool find(int s, int t) {
		v foot_stamp(nodes.size());
		return find(s, t, foot_stamp);
	}
};

int main() {
	int n = in(), m = in();
	graph g(n);
	g.read(m);
	int q = in();
	while (q--) {
		int s = in();
		out(g.find(s, in())? "yes" : "no", '\n');
	}
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <cctype>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true; else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	//return n; }
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	//if(n < 0) pcu('-'), n *= -1;
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
#undef svo
#undef si

#define v vector
struct graph {
	struct node {int n, w;};
	v<v<node>> nodes;

	void read(int n) {
		nodes.resize(n);
		for (auto &x: nodes) {
			in();
			for (int k = in(); k--;) {
				int c = in();
				x.push_back({c, in()});
			}
		}
	}

	v<node> dks() {
		v<node> w(nodes.size(), {0, INT_MAX});
		w[0].w = 0;
		priority_queue<node> q;
		q.push({0, 0});
		while (!q.empty()) {
			node n = q.top();
			q.pop();
			if (w[n.n].n)
				continue;
			w[n.n].n = 1;
			for (node &x: nodes[n.n]) {
				w[x.n].w = min(w[x.n].w, n.w + x.w);
				q.push({x.n, w[x.n].w});
			}
		}
		return move(w);
	}
};

bool operator < (const graph::node &a, const graph::node &b) {
	return a.w > b.w;
}

int main() {
	graph g;
	g.read(in());
	int i = 0;
	for (auto &x: g.dks())
		out(i++, ' ', x.w, '\n');
}

/* vim: set ts=4 noet: */
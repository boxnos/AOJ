#include <cstdio>
#include <cctype>
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
			gcu();
			for (int i = 0, w; i < n; i++)
				if ((w = in()) != -1)
					x.push_back({i, w});
		}
	}

	int mst_prim() {
		int w = 0;
		v<bool> visited(nodes.size());
		priority_queue<node> q;
		q.push({0, 0});
		while (!q.empty()) {
			node n = q.top();
			q.pop();
			if (visited[n.n])
				continue;
			w += n.w;
			visited[n.n] = true;
			for (node &i: nodes[n.n])
				q.push(i);
		}

		return w;
	}
};

bool operator < (const graph::node &a, const graph::node &b) {
	return a.w > b.w;
}

int main() {
	graph g;
	g.read(in());
	out(g.mst_prim(), '\n');
}

/* vim: set ts=4 noet: */

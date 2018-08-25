#include <cstdio>
#include <cctype>
#include <climits>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
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

template <typename T>
struct heap{
	vector<T> h = {T()};

	void insert(T x) {
		h.push_back(x);
		int c = h.size() - 1;
		for (int p = c / 2; p; c = p, p /= 2)
			if (h[p] < x)
				h[c] = move(h[p]);
			else
				break;
		h[c] = move(x);
	}
	T extract() {
		T res = move(h[1]);
		h[1] = h.back();
		T v = move(h[1]);
		h.pop_back();

		int p = 1, H = h.size();
		for (int c = 2; c < H; p = c, c = p * 2) {
			if (c + 1 < H && h[c] < h[c + 1])
				c++;
			if (h[c] < v)
				break;
			h[p] = move(h[c]);
		}
		h[p] = move(v);

		return move(res);
	}

	bool empty() {
		return h.size() == 1;
	}
};

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
		heap<node> q;
		q.insert({0, 0});
		while (!q.empty()) {
			node n = q.extract();
			if (w[n.n].n)
				continue;
			w[n.n].n = 1;
			for (node &x: nodes[n.n]) {
				int a = n.w + x.w;
				if (w[x.n].w > a) {
					w[x.n].w = a;
					q.insert({x.n, a});
				}
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

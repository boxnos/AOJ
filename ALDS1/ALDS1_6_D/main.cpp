#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
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


struct mcs {
	typedef vector<int> v;
	struct node {
		v w;
		int f, g, h;
	};
	node n;
	v s;

	mcs(int i) {
		n.w.resize(i);
		s.resize(i);

		for (int &x : n.w)
			x = in();
		s = n.w;
		sort(s.begin(), s.end());

		n.h = 0;
		auto b = s.begin();
		for (int a: n.w)
			if (a != *b++)
				n.h += a;
		n.f = n.h;
		n.g = 0;
	}

	int solve() {
		priority_queue<node> q;
		set<v> m;
		q.push(n);
		while (!q.empty()) {
			node a = q.top();
			q.pop();

			if (!a.h)
				return a.f;
			if (m.count(a.w))
				continue;
			m.insert(a.w);
			for (size_t i = 0; i < s.size() - 1; i++) {
				for (size_t j = i + 1; j < s.size(); j++) {
					node b = a;
					auto &w = b.w;
					swap(w[i], w[j]);
					b.g += w[i] + w[j];
					b.h += - w[i] - w[j] + (w[i] == s[i] ? 0 : w[i]) + (w[j] == s[j] ? 0 : w[j]);
					b.f = b.g + b.h;
					q.push(b);
				}
			}
		}
		return -1;
	}
};

bool operator < (const mcs::node &a, const mcs::node &b) {
	return a.f > b.f;
}

int main()
{
	mcs m(in());
	printf("%d\n", m.solve());
}

/* vim: set ts=4 noet: */

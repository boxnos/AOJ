#include <cstdio>
#include <cctype>
#include <array>
#include <set>
#include <queue>
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
//template <typename T>
//svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
#undef svo
#undef si

struct board {
	enum {size = 3};
	struct pos {int r, c;};
	typedef array<array<int, size>, size> arr;
	arr b;
	pos p;
	int cnt = 0;

	void read() {
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				b[i][j] = in();
				if (!b[i][j])
					p.r = i, p.c = j;
			}
	}
	void print() {
		for (auto &r: b) {
			for (int &c: r)
				out(&c == &r[0]?"":" ", c);
			out('\n');
		}
		out('\n');
	}

	int solver() {
		const arr end = {1, 2, 3, 4, 5, 6, 7, 8, 0};
		set<arr> m;
		queue<board> q;
		q.push(*this);
		while (!q.empty()) {
			board a = q.front();
			q.pop();
			if (a.b == end)
				return a.cnt;
			auto it = m.find(a.b);
			if (it != m.end())
				continue;
			m.insert(a.b);
			pos to[] = {
				a.p.r + 1, a.p.c,
				a.p.r, a.p.c + 1,
				a.p.r - 1, a.p.c,
				a.p.r, a.p.c - 1
			};
			for (pos o: to) {
				if (0 <= o.r && o.r < size && 0 <= o.c && o.c < size) {
					board c = a;
					swap(c.b[a.p.r][a.p.c], c.b[o.r][o.c]);
					c.p = o;
					c.cnt = a.cnt + 1;
					q.push(c);
				}
			}
		}
		return -1;
	}
};

int main() {
	board b;
	b.read();
	out(b.solver(), '\n');
}

/* vim: set ts=4 noet: */

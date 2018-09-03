#include <cstdio>
#include <cctype>
#include <array>
#include <unordered_set>
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
	int f, g, h;

	void read() {
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				b[i][j] = in();
				if (!b[i][j])
					p.r = i, p.c = j;
			}
		g = 0;
		f = h = hn(b);
	}

	void print() {
		for (auto &r: b) {
			for (int &c: r)
				out(&c == &r[0]?"":" ", c);
			out('\n');
		}
		out('\n');
	}

	static int hn(const arr &a) {
		int l = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				if (!a[i][j]) continue;
				int k = a[i][j] - 1;
				l += abs(i - k / size) + abs(j - k % size);
			}
		return l;
	}

	static int key(const arr &a) {
		int k = 0;
		for (auto &r: a)
			for (int c: r)
				k = (k * 10) + c;
		return k;
	}

	int solver() {
		static const pos to[] = {-1, 0, 0, -1, 1, 0, 0, 1};
		unordered_set<int> m;
		priority_queue<board> q;
		q.push(*this);
		while (!q.empty()) {
			board a = q.top();
			q.pop();
			int k = key(a.b);
			if (m.count(k))
				continue;
			m.insert(k);
			if (!a.h)
				return a.g;
			for (pos o: to) {
				o.r += a.p.r, o.c += a.p.c;
				if (0 <= o.r && o.r < size && 0 <= o.c && o.c < size) {
					board c = a;
					int f = c.b[o.r][o.c] - 1;
					c.h +=
						- abs(o.r - f / size) - abs(o.c - f % size)
						+ abs(a.p.r - f / size) + abs(a.p.c - f % size);
					swap(c.b[a.p.r][a.p.c], c.b[o.r][o.c]);
					c.g += 1;
					c.f = c.g + c.h;
					c.p = o;
					q.push(c);
				}
			}
		}
		return -1;
	}
};

bool operator < (const board &a, const board &b) {
	return a.f > b.f;
}

int main() {
	board b;
	b.read();
	out(b.solver(), '\n');
}

/* vim: set ts=4 noet: */

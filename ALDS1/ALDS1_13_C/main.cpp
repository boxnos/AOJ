#include <cstdio>
#include <cctype>
#include <array>
#include <unordered_map>
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
	enum {size = 4};
	struct pos {int r, c;};
	typedef array<array<int, size>, size> arr;
	typedef unordered_map<long, int> mp;

	int h;
	arr b;
	pos p;

	void read() {
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				b[i][j] = in();
				if (!b[i][j])
					p.r = i, p.c = j;
			}
		h = hn(b);
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
				if (!a[i][j])
					continue;
				int k = a[i][j] - 1;
				l += abs(i - k / size) + abs(j - k % size);
			}
		return l;
	}

	static long key(const arr &a) {
		long k = 0;
		for (auto &r: a)
			for (int c: r)
				k = (k * 10) + c;
		return k;
	}

	static bool dfs(board &a, mp &m, int depth, int limit) {
		static const pos to[] = {-1, 0, 0, -1, 1, 0, 0, 1};
		if (!a.h)
			return true;

		if (depth + a.h > limit)
			return false;

		long k = key(a.b);
		auto res = m.find(k);
		if (res != m.end() && (*res).second <= depth)
			return false;

		pos tp = a.p;
		int th = a.h;
		for (pos o: to) {
			o.r += tp.r, o.c += tp.c;
			if (0 <= o.r && o.r < size && 0 <= o.c && o.c < size) {
				swap(a.b[tp.r][tp.c], a.b[o.r][o.c]);
				int f = a.b[tp.r][tp.c] - 1;
				a.h = th
					+ abs(tp.r - f / size) + abs(tp.c - f % size)
					- abs(o.r - f / size) - abs(o.c - f % size);
				a.p = o;
				if (dfs(a, m, depth + 1, limit))
					return true;
				swap(a.b[o.r][o.c], a.b[tp.r][tp.c]);
			}
		}
		a.p = tp;
		a.h = th;
		if (res == m.end() || (*res).second > depth)
			m[k] = depth;
		return false;
	}

	int solver() {
		int limit = h;
		for (;;limit += 2) {
			mp m = {};
			if(dfs(*this, m, 0, limit))
				return limit;
		}
	}
};

int main() {
	board b;
	b.read();
	out(b.solver(), '\n');
}

/* vim: set ts=4 noet: */

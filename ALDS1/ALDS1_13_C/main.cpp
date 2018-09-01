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
	typedef array<pos, size * size> ap;
	typedef array<ap, 2> aap;
	typedef array<array<int, size>, size> arr;

	arr b;
	pos p;
	int f, g, h, d;

	void read() {
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				int f = in();
				b[i][j] = f;
				if (!f)
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

	static int hn(const arr &a, ap mt) {
		int l = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				int k = a[i][j];
				if (!k) continue;
				l += abs(i - mt[k].r) + abs(j - mt[k].c);
			}
		return l;
	}

	static long key(const arr &a) {
		long k = 0;
		for (auto &r: a)
			for (int c: r)
				k = (k * 16) + c;
		return k;
	}

	void init_solver(aap &mt, board &e) {
		for (int i = 0; i < size * size; i++)
			if (!i)
				mt[0][i] = {size - 1, size - 1};
			else
				mt[0][i] = {(i - 1) / size, (i - 1) % size};
		for (int i = 0, k = 1; i < size; i++)
			for (int j = 0; j < size; j++) {
				mt[1][b[i][j]] = {i, j};
				 e.b[i][j] = k == size * size ? 0 : k++;
			}
	}

	int solver() {
		static const pos to[] = {-1, 0, 0, -1, 1, 0, 0, 1};
		unordered_map<long, pos> m;
		priority_queue<board> q;
		aap mt;

		board e = *this;
		init_solver(mt, e);
		e.d = 1;
		e.p = {size - 1, size - 1};

		g = d = e.g = 0;
		f = h = hn(b, mt[d]);
		e.f = e.h = hn(e.b, mt[e.d]);

		int beam = 100000, beam_count = 12;

		q.push(*this);
		q.push(e);
		while (!q.empty()) {
			board a = q.top();
			q.pop();
			long k = key(a.b);
			auto res = m.find(k);
			if (res != m.end()) {
				if ((*res).second.r == a.d)
					continue;
				else if (!beam_count--)
						return beam;
				else {
					beam = min(beam, a.g + (*res).second.c);
					continue;
				}
			}
			m[k] = {a.d, a.g};
			if (!a.h)
				return a.g;
			for (pos o: to) {
				o.r += a.p.r, o.c += a.p.c;
				if (0 <= o.r && o.r < size && 0 <= o.c && o.c < size) {
					board c = a;
					pos f = mt[c.d][c.b[o.r][o.c]];
					c.h +=
						- abs(o.r - f.r) - abs(o.c - f.c)
						+ abs(a.p.r - f.r) + abs(a.p.c - f.c);
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

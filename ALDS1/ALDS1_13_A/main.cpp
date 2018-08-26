#include <cstdio>
#include <cctype>
#include <array>
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
	array<array<int, 8>, 8> b = {};

	void print() {
		for (auto r : b) {
			for (int c : r)
				//out(c == 2 ? 'Q' : c == 1 ? 'X' : '.');
				out(c == 2 ? 'Q' : '.');
			out('\n');
		}
	}

	board put(int r, int c) {
		board t = *this;
		auto cross = [&](int r, int c) {
			if (0 <= r && r < 8 && 0 <= c && c < 8)
				t.b[r][c] = 1;
		};
		for (int i = 0; i < 8; i++) {
			t.b[i][c] = t.b[r][i] = 1;
			cross(r + i, c + i);
			cross(r - i, c - i);
			cross(r + i, c - i);
			cross(r - i, c + i);
		}
		t.b[r][c] = 2;
		return move(t);
	}

	bool solver(int r) {
		if (r >= 8) {
			print();
			return true;
		}
		for (int i = 0; i < 8; i++)
			if (!b[r][i]) {
				board t = put(r, i);
				if (t.solver(r + 1))
					return true;
			} else if (b[r][i] == 2)
				return solver(r + 1);
		return false;
	}
};

int main() {
	board b;
	int k = in();
	while (k--) {
		int r = in();
		b = b.put(r, in());
	}
	b.solver(0);
}

/* vim: set ts=4 noet: */

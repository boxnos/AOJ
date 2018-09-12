#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

#define gcu getchar_unlocked
int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
void scan(string &s) {for (char c; !isspace(c = gcu()); s += c);}
#define pcu putchar_unlocked
template <typename T>
void out(T n) {
	static char buf[20];
	char *p = buf;
	//if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
void out(const char *s){while(*s)pcu(*s++);}
void out(char c){pcu(c);}
void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

#define v vector
typedef v<string> vs;

struct rect_search {
	
	vs T, P;
	int H, W, R, C;

	static void read(int &r, int &c, vs &S) {
		r = in();
		c = in();
		S = vs(r);
		for (auto &s: S)
			scan(s);
	}
	rect_search() {
		read(H, W, T);
		read(R, C, P);
	}

	void search () {
		for (int i = 0; i <= H - R; i++)
			for (int j = 0; j <= W - C; j++) {
				int k = 0;
				for (; k < R; k++)
					if (P[k] != T[i + k].substr(j, C))
						break;
				if (k == R)
					out(i, ' ', j, '\n');
			}

	}

	void print() {
		for (auto r: T)
			out(r, '\n');
		for (auto r: P)
			out(r, '\n');
	}
};

int main() {
	rect_search rs = rect_search();
	rs.search();
	// rs.print();
}

/* vim: set ts=4 noet: */

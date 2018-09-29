#include <cstdio>
#include <utility>

#include <vector>
#include <string>
using namespace std;

#define gcu getchar_unlocked
#define ii inline int in
#define is inline bool scan
ii(int c) {
	int n = 0;
	bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	//return n; }
	return minus ? -n : n; }
ii() {return in(gcu());}
is(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
is(char &c){c=gcu();gcu();return c!=EOF;}
is(string &s) {int c;for(;;){c=gcu();if(c=='\n'||c==' ')return true;s+=c;}}
#undef ii
#define pcu putchar_unlocked
template <typename T>
void out(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
void out(const char *s){while(*s)pcu(*s++);}
void out(char c){pcu(c);}
void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

typedef vector<string> map;

bool divide(map &m, char c, int x, int y) {
	if (x < 0 || x >= (int) m[0].size() || y < 0 || y >= (int) m.size() ||
		c == '.' || m[y][x] != c)
		return false;
	m[y][x] = '.';
	static const int nx[4] = {1, 0, -1, 0}, ny[4] = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++)
		divide(m, c, x + nx[i], y + ny[i]);
	return true;
}

int main() {
	int H, W;
	while (H = in(), W = in(), H || W) {
		int sections = 0;
		map m = map(H);
		for (string &s : m)
			scan(s);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (divide(m, m[i][j], j, i))
					sections++;

		out(sections, '\n');
		/*
		for (string s : m)
			out(s, '\n');
		*/
	}
}

/* vim: set ts=4 noet: */

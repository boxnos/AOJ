#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
using namespace std;

#define gcu getchar_unlocked
#define ii inline int in
ii(int c) {
	int n = 0;
	bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	//return n; }
	return minus ? -n : n; }
ii() {return in(gcu());}
inline bool scan(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
//void scan(string &s) {int c;do{c=gcu();s+=c;}while(!(c=='\n'||c==' '));}
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
//void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

typedef vector<vector<int>> map;

bool walk(int x, int y, map &m) {
	static const int
		dx[] = {1, 1, 0, -1, -1, -1, 0, 1},
		dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
	if (x < 0 || x >= (int) m[0].size() ||
		y < 0 || y >= (int) m.size() ||
		m[y][x] == 0)
		return false;
	m[y][x] = 0;
	int i = 0;
	for (; i < 8; i++)
		walk(x + dx[i], y + dy[i], m);
	return true;
}

int main() {
	int W, H;
	while(scan(W) && scan(H) && (W || H)) {
		map m(H, vector<int>(W));
		for (auto &v: m)
			for (int &i :v)
				i = in();
		int c = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (walk(j, i, m))
					c++;
		//for (auto v : m)
		//	out(v);
		//out('\n');
		out(c, '\n');
	}
}

/* vim: set ts=4 noet: */

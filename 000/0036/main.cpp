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
is(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
is(char &c){c=gcu();gcu();return c!=EOF;}
is(string &s){int c; s = "";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
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
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

typedef vector<string> v;

char pat_search(v &a) {
	static auto p = [&a](int i, int j) {
		return i < 8 && j < 8 && a[i][j] == '1';};
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (a[i][j] == '1') {
				return p(i + 1, j + 1)? p(i, j + 1)? p(i + 1, j + 2)? 'E' : 'A' : 'F' :
					p(i, j + 1)? p(i, j + 2)? 'C' : 'G' : p(i + 2, j)? 'B' : 'D';
			}
	return 'X';
}

int main() {
	v a(8);
	do {
		for (auto &s: a)
			scan(s);
		out(pat_search(a), '\n');
	} while (gcu() == '\n');
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;

#define gcu getchar_unlocked
int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
//void scan(string &s) {for (char c; !isspace(c = gcu()); s += c);}
bool scan(int &n) {n = in(); int c = gcu(); return (c != EOF)? ungetc(c, stdin), true: false;}
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
//void out(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail>
void out(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

int cnt = 0;
int f(int n, int s, int j) {
	cnt++;
	if (n == 1)
		return s >= j ? 1 : 0;
	int c = 0;
	for (int i = j; i <= 9; i++)
		if (s - i >= 0)
			c += f(n - 1, s - i, i + 1);
		else
			break;
	return c;
}

int main() {
	int n, s;
	while (scan(n) && scan(s) && (n || s))
		out(f(n, s, 0), '\n');
	cerr << cnt << endl;
}

/* vim: set ts=4 noet: */

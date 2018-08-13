#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true; else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
//svo(vector<T> v){for(T &x:v)out(' '),out(x);out('\n');}
svo(vector<T> &v){for(int &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;

int main() {
	int n = in();
	v h(n);
	for (int &x: h)
		x = in();

	for (int i = 1, p, l, r; i <= n; i++) {
		p = i / 2, l = 2 * i, r = 2 * i + 1;
		out("node ", i, ": key = ", h[i - 1], ", ");
		if (p)
			out("parent key = ", h[p - 1], ", ");
		if (l <= n)
			out("left key = ", h[l - 1], ", ");
		if (r <= n)
			out("right key = ", h[r - 1], ", ");
		out('\n');
	}
}

/* vim: set ts=4 noet: */

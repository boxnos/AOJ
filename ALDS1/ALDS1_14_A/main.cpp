#include <cstdio>
#include <cctype>
#include <utility>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int n = 0, c = gcu();
	// bool minus = false; if (c == '-') minus = true, c = gcu();
	do {n = 10 * n + (c - '0'), c = gcu();} while (c >= '0');
	return n; }
	// return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu())); *s++ = '\0';}
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

int main() {
	char t[1001], p[1001];
	scan(t);
	scan(p);
	int i = 0;
	for (char *j = t; *j; j++, i++) {
		char *a = j, *b = p;
		while (*b && *a++ == *b++)
			;
		if (*b == '\0')
			out(i, '\n');
	}
}

/* vim: set ts=4 noet: */

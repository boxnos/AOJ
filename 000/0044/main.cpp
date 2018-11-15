#include <cstdio>
#include <utility>
#include <cmath>
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
//is(string &s){int c;
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
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
//template <typename T>
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

unsigned long powm(int b, int n, int m) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return b % m;
	unsigned long t = powm(b, n / 2, m);
	return t * t % m * (n % 2 ? b : 1) % m;
}


bool fermat(int n) {
	for (int i = 0; i < log(n) * 5; i++) {
		int r = rand();
		if (r % n && powm(r, n - 1, n) != 1)
			return false;
	}
	return true;
}

bool is_prime(int n) {
	return fermat(n);
}

int main() {
	for (int n; scan(n);) {
		for (int i = n - 1;; i--)
			if(is_prime(i)) {
				out(i, ' ');
				break;
			}
		for (int i = n + 1;; i++)
			if(is_prime(i)) {
				out(i, '\n');
				break;
			}
	}
}

/* vim: set ts=4 noet: */
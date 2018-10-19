#include <cstdio>
#include <utility>
#include <vector>
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
//is(string &s){int c; s = "";
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
template <typename T>
void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

int odd_divisor_count(int n) {
	static const vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	struct D {int n, k;};
	vector<D> d;

	for (int i = 0; n != 1 && p[i] * p[i] <= n; i++) {
		D tmp = {p[i], 0};
		while (!(n % p[i])) {
			tmp.k++;
			n /= p[i];
		}
		if(tmp.k)
			d.push_back(tmp);
	}
	if (n != 1)
		d.push_back({n, 1});

	int pd = 1;
	for (D x: d)
		if (x.n != 2)
			pd *= x.k + 1;
	return pd - 1;
}

int main() {
	for (int n; (n = in());)
		out(odd_divisor_count(n), '\n');
}

/* vim: set ts=4 noet: */

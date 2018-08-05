#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true;
	else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return minus ? -n : n; }
#define pcu putchar_unlocked
#define svo si void out
svo(int n) {
	static char buf[20];
	char *p = buf;
	bool minus = false;
	if(n < 0) minus = true, n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	if (minus) *p++ = '-';
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
svo(vector<T> v){for(int &x:v)out(&x == &v[0]?"":" ",x);out('\n');}

typedef vector<int> v;
typedef v::iterator vi;
bool first = true;
void walk(vi &b, vi l, vi r)
{
	vi c = find(l, r, *b);
	if (c == r)
		return;
	b++;
	walk(b, l, c);
	walk(b, c + 1, r);
	out(first ? first = false, "" : " ", *c);
}

int main()
{
	int n = in();
	v p(n), i(n);
	for (int &x: p) x = in();
	for (int &x: i) x = in();

	vi b = p.begin();
	walk(b, i.begin(), i.end());
	out('\n');
}

/* vim: set ts=4 noet: */

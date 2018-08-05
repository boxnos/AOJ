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
si void out(int n) {
	static char buf[20];
	char *p = buf;
	bool minus = false;
	if(n < 0) minus = true, n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	if (minus) *p++ = '-';
	while (p != buf) pcu(*--p); }
si void out(const char *s){while(*s)pcu(*s++);}
si void out(char c){pcu(c);}

template <typename head, typename... tail>
si void out(head&& h, tail&&... t){out(h);out(move(t)...);}
template <typename T>
si void out(vector<T> v) {
	for (int &x: v)
		out(&x == &v[0] ? "": " ", x);
	out('\n');
}

typedef vector<int> v;
typedef v::iterator vi;
v buf;
bool walk(vi &pb, vi pe, vi ib, vi ie)
{
	if (pb == pe)
		return false;

	vi res = find(ib, ie, *pb);
	if (res == ie)
		return true;
	pb++;

	if (walk(pb, pe, ib, res) && walk(pb, pe, res + 1, ie)) {
		buf.push_back(*res);
		return true;
	}
	buf.push_back(*res);
	return false;
}

int main()
{
	int n = in();
	v p(n);
	v i(n);

	for (int &x: p)
		x = in();

	for (int &x: i)
		x = in();

	vi b = p.begin();
	walk(b, p.end(), i.begin(), i.end());
	out(buf);
}

/* vim: set ts=4 noet: */

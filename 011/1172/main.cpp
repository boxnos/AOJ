#include <cstdio>
#include <utility>
#include <vector>
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
is(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
is(char &c){c=gcu();gcu();return c!=EOF;}
//is(string &s) {int c;for(;;){c=gcu();if(c=='\n'||c==' ')return true;s+=c;}}
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

vector<int> sieve;

void make_sieve(int m) {
	sieve = vector<int>(m, true);
	for (int i = 4; i < m; i += 2)
		sieve[i] = false;
	for (int i = 3, e = sqrt(m); i <= e; i += 2) {
		if (!sieve[i])
			continue;
		for (int j = i * i; j < m; j += i)
			sieve[j] = false;
	}
}

int main()
{
	int n, m = 0;
	vector<int> d;
	while ((n = in())) {
		d.push_back(n);
		m = max(m, n);
	}

	make_sieve(m * 2 + 1);
	vector<int> map(m * 2 + 1);

	int c = 0;
	for (int i = 2; i <= m * 2; i++)
		map[i] = sieve[i] ? ++c: c;

	for (int p: d)
		out(map[p * 2] - map[p], '\n');
}

/* vim: set ts=4 noet: */

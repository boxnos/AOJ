#include <cstdio>
#include <utility>
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
//void scan(string &s) {for (char c; !isspace(c = gcu()); s += c);}
inline bool scan(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
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
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

int main() {
	int a, rect = 0, rhombus = 0;
	while (scan(a)) {
		int b = in(), c = in();
		if (a * a + b * b == c * c)
			rect++;
		else if (a == b)
			rhombus++;
	}
	out(rect, '\n', rhombus, '\n');
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <utility>
#include <unordered_map>
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
inline bool scan(int &n) {int c=gcu();return c==EOF?false:(n=in(c),true);}
void scan(string &s) {int c;do{c=gcu();s+=c;}while(!(c=='\n'||c==' '));}
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
#undef svo

void skip() {
	int c;
	while (isspace(c = gcu()))
		;
	ungetc(c, stdin);
}

int main() {
	int n;
	while ((n = in())) {
		unordered_map<char, char> m = {};
		while (n--) {
			char c = gcu(); gcu();
			char d = gcu();
			skip();
			m[c] = d;
		}
		int l = in();
		while (l--) {
			char c = gcu();
			skip();
			out(m.count(c) ? m[c] : c);
		}
		out("\n");
	}
}

/* vim: set ts=4 noet: */

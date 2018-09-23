#include <cstdio>
#include <cctype>
#include <utility>
#include <map>
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
//void scan(string &s) {int c;do{c=gcu();s+=c;}while(!(c=='\n'||c==' '));}
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
//template <typename T>
//void out(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
//void out(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef svo

int main() {
	float w;
	map<float, string> Class = {
		{48.00, "light fly"}, {51.00, "fly"}, {54.00, "bantam"}, {57.00, "feather"},
		{60.00, "light"}, {64.00, "light welter"}, {69.00, "welter"}, {75.00, "light middle"},
		{81.00, "middle"}, {91.00, "light heavy"}, {1.0e5, "heavy"}};
	while (scanf("%f", &w) != EOF)
		out((*Class.lower_bound(w)).second, '\n');
}

/* vim: set ts=4 noet: */

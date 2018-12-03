#include <cstdio>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
int in() {return in(gcu());}
bool scan(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bool scan(char &c){c=gcu();gcu();return c!=EOF;}
//bool scan(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
template <typename head, typename... tail>
bool scan(head &h, tail&&... t){return scan(h) && scan(t...);}
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
//vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename... tail> void outl(tail&&... t) {out(move(t)...); out('\n');}
#undef vo

int tax(int p, int r) {
	return p * (100 + r) / 100;
}
int fix(int p, int r) {
	return p - p * r / (100 + r);
}

int main() {
	for (int x, y, s; x = in(), y = in(), s = in(), x || y || s;) {
		int m = INT_MIN;
		for (int i = 1, e = s / 2; i <= e; i++) {
			int a = fix(i, x), b = fix(s - i, x);
			if (tax(a, x) + tax(b, x) == s)
				m = max(m, tax(a, y) + tax(b, y));
		}
		outl(m);
	}
}

/* vim: set ts=4 noet: */

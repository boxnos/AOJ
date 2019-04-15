#include <cstdio>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;while(isspace(c)){c=gcu();}if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
_vo(bool b) {pcu('0'+b);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_vo(string s){for(char c:s)pcu(c);}
#endif
_T _vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

struct Q {
	int n, c, o;
};

int pow10(int p) {
	return pow(10, p);
}

unordered_map<int, int> all() {
	static const int r[] = {1, 4, -1, -4};
	unordered_map<int, int> m;
	queue<Q> q;
	q.push({1234567, 0, 7});
	m[1234567] = 0;
	while (!q.empty()) {
		Q a = q.front();
		q.pop();
		for (auto x: r) {
			int p = x + a.o;
			if (p >= 0 && p < 8 && !(p == 4 && x == 1) && !(p == 3 && x == -1)) {
				int t = a.n + a.n / pow10(p) % 10 * (pow10(a.o) - pow10(p));
				if (!m.count(t)) {
					m[t] = a.c + 1;
					q.push({t , a.c + 1, p});
				}
			}
		}
	}
	return move(m);
}

int main() {
	unordered_map<int, int> m = all();
	for (;;) {
		int t = 0;
		for (int i = 0, a; i < 8; i++) {
			if (!scan(a))
				return 0;
			t *= 10;
			t += a;
		}
		outl(m[t]);
	}
}

/* vim: set ts=4 noet: */

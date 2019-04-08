#include <cstdio>
#include <cctype>
#include <utility>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;while(isspace(c)){c=gcu();}if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m?-n:n;}
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

struct table {
	int t[51];
	table() : t() {
		map<int, int> m = {{2, 380}, {3, 550}, {5, 850}, {10, 1520}, {12, 1870}, {15, 2244}};
		for (int i = 2; i < 51; i++) {
			int r = INT_MAX;
			if (m.count(i))
				r = m[i];
			else
				for (auto p: m) {
					if (p.first > i - p.first)
						break;
					r = min(r,  p.second + t[i - p.first]);
				}
			t[i] = r;
		}
	}
};

int main() {
	table t;
	for (int a; (a = in());)
		outl(t.t[a/100]);
}

/* vim: set ts=4 noet: */

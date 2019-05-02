#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <complex>
#include <algorithm>
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

using C = complex<int>;
using V = vector<C>;
#define all(a) a.begin(), a.end()

void shift(V &v) {
	C c = v[0], &d = v[1];
	for_each(all(v), [c](auto &x) {x -= c;});
	C r = d.imag() < 0 ? C{0, 1} : d.imag() > 0 ? C{0, -1} :
		  d.real() < 0 ? C{-1, 0} : C{1, 0};
	for_each(1 + all(v), [r](auto &x) {x *= r;});
}

V read () {
	V v(in());
	for (auto &x: v)
		x = {in(), in()};
	shift(v);
	return move(v);
}

int main() {
	for (int n; (n = in());) {
		V a = read();
		vector<V> v = {a, (reverse(all(a)), shift(a), a)};
		for (int i = 1; i <= n; i++) {
			V b = read();
			if(find(all(v), b) != v.end())
				outl(i);
		}
		outl("+++++");
	}
}

/* vim: set ts=4 noet: */

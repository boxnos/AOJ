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

V read () {
	V v(in());
	C c = {in(), in()};
	v[0] = {0, 0};
	for_each(v.begin() + 1, v.end(), [&](auto &x) {x = C{in(), in()} - c;});
	return move(v);
}

int main() {
	for (int n; (n = in());) {
		V a = read(), b;
		vector<V> v(8);
		auto rot = [&a](auto b, auto e) {
			for_each (b, e, [&a](auto &x) {
					  x = a;
					  for_each(a.begin() + 1, a.end(), [](auto &x) {x *= C{0, 1};});});
		};
		rot(v.begin(), v.begin() + 4);
		reverse(a.begin(), a.end());
		C c = a[0];
		for_each(a.begin(), a.end(), [=](auto &x) {x -= c;});
		rot(v.begin() + 4, v.end());
		for (int i = 1; i <= n; i++) {
			b = read();
			if(find(v.begin(), v.end(), b) != v.end())
				outl(i);
		}
		outl("+++++");
	}
}

/* vim: set ts=4 noet: */

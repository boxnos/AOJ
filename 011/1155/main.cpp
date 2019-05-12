#include <cstdio>
#include <cctype>
#include <utility>
#include <string>
#include <functional>
#include <array>
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

using A = array<int, 3>;

function<int(A &)> f(string::iterator &i) {
	switch (*i) {
	case '0': case '1': case '2':
		{
			char c = *i++ - '0';
			return [c](...) { return c; };
		}
	case 'P': case 'Q': case 'R':
		{
			int j = *i == 'P' ? 0 : *i == 'Q' ? 1 : 2;
			i++;
			return [j](A &e) { return e[j]; };
		}
	case '-':
		{
			auto a = f(++i);
			return [a](A &e) { return 2 - a(e); };
		}
	default:
		{
			auto a = f(++i);
			char op = *i;
			auto b = f(++i);
			i++;
			if (op == '*')
				return [a, b](A &e) { return min(a(e), b(e)); };
			else
				return [a, b](A &e) { return max(a(e), b(e)); };
		}
	}
}

int main() {
	for (string s; scan(s), s[0] != '.';) {
		auto i = s.begin();
		auto e = f(i);
		A t;
		function<int(int, int)> loop = [&](int i, int a) {
			if (i--) {
				for (t[i] = 0; t[i] < 3; t[i]++)
					a = loop(i, a);
				return a;
			} else
				return a + (e(t) == 2);
		};
		outl(loop(3, 0));
	}
}

/* vim: set ts=4 noet: */

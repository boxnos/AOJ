#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <string>
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

using V = vector<int>;
struct P {int a, b;};

bool f(int i, V &m, P c) {
	if (!(c.a || c.b))
		return true;
	while (!m[i])
		i++;
	bool r = false;
	if (c.a && m[i] >= 3) {
		m[i] -= 3, c.a--;
		r = f(i, m, c);
		m[i] += 3, c.a++;
		if (r)
			return true;
	}
	if (c.a && i < 8 && m[i] && m[i + 1] && m[i + 2]) {
		m[i]--, m[i + 1]--, m[i + 2]--, c.a--;
		r = f(i, m, c);
		m[i]++, m[i + 1]++, m[i + 2]++, c.a++;
		if (r)
			return true;
	}
	if (c.b && m[i] >= 2) {
		m[i] -= 2, c.b--;
		r = f(i, m, c);
		m[i] += 2, c.b++;
		if (r)
			return true;
	}
	return r;
}

int main() {
	for (string s; scan(s);) {
		V m(9), r;
		for (int c: s)
			m[c - '0' - 1]++;
		for (int i = 0; i < 9; i++)
			if (m[i] < 4) {
				m[i]++;
				if (f(0, m, P{4, 1}))
					r.push_back(i + 1);
				m[i]--;
			}
		if (r.size())
			out(r);
		else
			outl(0);
	}
}

/* vim: set ts=4 noet: */

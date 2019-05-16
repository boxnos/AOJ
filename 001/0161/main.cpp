#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
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
_T _vo(T n){static char buf[20];char *p=buf;if(n<0)pcu('-'),n*=-1;
	if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10; while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

struct T {
	int i, s;
	bool operator < (const T a) const { return s < a.s; }
};

int main() {
	for (int n; (n = in());) {
		vector<T> l(n);
		for (T &t:l) {
			t.i = in();
			for (int i = 0; i < 4; i++) {
				t.s += in() * 60;
				t.s += in();
			}
		}
		partial_sort(l.begin(), l.begin() + 2, l.end());
		outl(l[0].i);
		outl(l[1].i);
		nth_element(l.begin(), l.begin() + n - 2, l.end());
		outl(l[n - 2].i);
	}
}

/* vim: set ts=4 noet: */

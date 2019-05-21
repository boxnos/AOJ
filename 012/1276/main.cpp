#include <cstdio>
#include <cctype>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _sc _il bool scan
_T T in(int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_il int in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _ot _il void out
#define _ol _il void outl
_ot(bool b) {pcu('0'+b);}
_ot(const char *s){while(*s)pcu(*s++);}
_ot(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_ot(string s){for(char c:s)pcu(c);}
#endif
_T _ot(T n){static char b[20];char *p=b,m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=n%10*m+'0',n/=10;while(p!=b)pcu(*--p);}
_ol(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _ot(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _ot(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _ol(T&&... t){out(move(t)...);outl();}

template<int N>
struct sieve {
	bool s[N];
	int v[N], l = -1;
	sieve() : s(), v() {
		for (int i = 0; i < N; i++)
			s[i] = true;
		for (int i = 4; i < N; i += 2)
			s[i] = false;
		for (int i = 9; i < N; i += 6)
			s[i] = false;
		for (int i = 6, e = sqrt(N); i <= e; i += 6) {
			for (int j : {i - 1, i + 1})
				if (s[j])
					for (int k = j * j; k < N; k += j)
						s[k] = false;
		}
		for (int i = 2; i < N; i++)
			if (s[i])
				v[++l] = i;;
	}
};

int main() {
	sieve<1300000> s;
	for (int n; (n = in());) {
		if (s.s[n])
			outl(0);
		else {
			auto i = lower_bound(s.v, s.v + s.l, n);
			outl(*i - *(i - 1));
		}
	}
}

/* vim: set ts=4 noet: */

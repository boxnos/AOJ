#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <cmath>
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
	constexpr sieve() : s(), v() {
		s[2] = true;
		for (int i = 3; i < N; i += 2)
			s[i] = true;
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
	constexpr sieve<10001> s;
	for (int n; scan(n);) {
		int c = 0;
		if (n & 1) {
			for (auto i = s.v; *i <= n / 2; i++)
				if (s.s[n - *i + 1])
					c++;
			c = c * 2 + s.s[n / 2 + 1];
		} else
			c = s.s[n - 1] * 2;
		outl(c);
	}
}

/* vim: set ts=4 noet: */

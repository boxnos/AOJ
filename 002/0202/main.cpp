#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const auto gcu = getchar_unlocked;
const auto pcu = putchar_unlocked;
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
_T _DEF(T,in,int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_DEF(int, in){return in<int>(gcu());}
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_T _SCAN(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_DEF(bool, scan, char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_SCAN(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_OUT(string s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b,m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=n%10*m+'0',n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}

template<int N>
struct sieve {
	bool s[N];
	sieve() : s() {
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
	}
};

int main() {
	sieve<1000001> s;
	for (int n, x; n = in(), x = in();) {
		vector<int> dp(x + 1);
		dp[0] = true;
		while (n--) {
			int v = in();
			for (int i = v; i <= x; i++)
				if (dp[i - v])
					dp[i] = true;
		}
		int r = [&] {
		for (int i = x; i > 1; i--)
			if (dp[i] && s.s[i])
				return i;
		return 0;}();
		if (r)
			outl(r);
		else
			outl("NA");
	}
}

/* vim: set ts=4 noet: */

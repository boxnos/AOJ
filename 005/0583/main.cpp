#include <cstdio>
#include <cctype>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
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

template<int N>
struct sieve {
	bool s[N];
	int v[N], l = -1;
	constexpr sieve() : s(), v() {
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
	constexpr int N = sqrt(100000000);
	sieve<N> s;
	int n = in(), c = in();
	while (--n)
		c = __gcd(c, in());

	vector<pair<int, int>> a;
	for (int i = 0; ; i++) {
		if (c >= s.v[i] * s.v[i]) {
			while (c % s.v[i] == 0) {
				c /= s.v[i];
				if (a.size() && a.back().first == s.v[i])
					a.back().second++;
				else
					a.push_back({s.v[i], 1});
			}
		} else if (c == 1)
			break;
		else {
			a.push_back({c, 1});
			break;
		}
	}

	vector<int> r = {1};
	for (auto p: a) {
		size_t i = 0;
		while (p.second--) {
			size_t e = r.size();
			for (; i < e; i++)
				r.push_back(r[i] * p.first);
		}
	}
	sort(r.begin(), r.end());

	for (int x: r)
		outl(x);
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

#define _gp(l) const auto gcu{getchar##l}; const auto pcu{putchar##l}
#ifdef __linux
_gp(_unlocked);
#else
_gp();
#endif
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
_T _DEF(T,in,int c){T n=0;int m=1;while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_DEF(int,in,){return in<int>(gcu());}
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_T _SCAN(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_DEF(bool, scan, int &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_SCAN(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=(char)c;}}
#endif
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);} _OUT(const char *s){while(*s)pcu(*s++);} _OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_OUT(string s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}
struct range{
	int e,b=0,s=1; range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it { int v, s; it (int _v, int _s) : v(_v), s(_s) {} operator int()const{return v;} operator int&(){return v;} int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin() {return {b, s};} it end() {return {e, s};}};

struct edge {int t, c, r;};

int main() {
	int v {in()}, e {in()};
	vector<vector<edge>> G(v);
	vector<bool> V(v);
	for (int i = 0; i < e; i++) {
		int f {in()}, t{in()}, c {in()};
		G[f].push_back({t, c, (int) G[t].size()});
		G[t].push_back({f, 0, (int) G[f].size() - 1});
	}
	function<int(int, int, int)> res {[&](int v, int t, int f) {
		if (v == t)
			return f;
		V[v] = true;
		for (edge &e: G[v])
			if (!V[e.t] && e.c > 0) {
				int d {res(e.t, t, min(f, e.c))};
				if (d > 0) {
					e.c -= d;
					G[e.t][e.r].c += d;
					return d;
				}
			}
		return 0;
	}};
	int f {};
	for (int r {INT_MAX}; r; f += r = res(0, v - 1, INT_MAX))
		fill(begin(V), end(V), false);
	outl(f);
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <utility>
#include <vector>
#include <deque>
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
#define _OP(t) inline operator t()
struct _in {
#ifdef _GLIBCXX_STRING
	_OP(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n';)s+=c;return s;}
#define _S
#endif
	_OP(char){char c=gcu();gcu();return c;}
	_OP(double){double d; scanf("%lf",&d); gcu();return d;}
	_T _OP(T){T n{},m{1},c;if((c=gcu())=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
} in;
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
#ifdef _S
_SCAN(string &o) {int c{gcu()};if(c==EOF)return false;else{ungetc(c,stdin);string t=move(in);o=t;return true;}}
#endif
_T _SCAN(T &o) {int c{gcu()};return c==EOF?false:(ungetc(c,stdin),o=in,true);}
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _S
_OUT(string &s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
	_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
	_T _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
	_HT _OUT(H &&h, T... t){out(h);out(t...);}
	template <typename... T> _OUTL(T... t){out(t...);outl();}
	struct range{
		int e,b=0,s=1;range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
		struct it{int v,s; it(int _v,int _s):v(_v),s(_s){} operator int()const{return v;} operator int&(){return v;}int operator*()const{return v;}
			it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

struct T {
	struct N {
		int p, m;
	};
	vector<N> t;
	T (int n) {
		t.resize(n);
		t[0] = {0, 0};
		for (int i: range(1, n))
			t[i] = {(int) in - 1, INT_MAX};
	}
	int Q (int v, int i) {
		if (t[v].m < i)
			return v;
		else
			return t[v].p = Q(t[v].p, i);
	}
	void M (int v, int i) {
		if (t[v].m == INT_MAX)
			t[v].m = i;
	}
};


struct Q {
	int v, i;
};

int main() {
	for (int N, M; N = in, M = in;) {
		T t(N);
		deque<Q> q;
		for(int i: range(1, M + 1)) {
			char c {in};
			int v {in};
			if (c == 'Q')
				q.push_front({v - 1, i});
			else
				t.M(v - 1, i);
		}
		long r {};
		for (auto i: q)
			r += t.Q(i.v, i.i) + 1;
		outl(r);
	}
}

/* vim: set ts=4 noet: */

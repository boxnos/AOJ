#include <cstdio>
#include <utility>
#include <cctype>
#include <complex>
#include <vector>
using namespace std;

#ifdef __linux
#define _U(s) s##_unlocked
#else
#define _U(s) _##s##_nolock
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
#define gcu _U(getchar)
#define pcu _U(putchar)
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
#define _OP(t) inline operator t()
struct _in {
#ifdef _GLIBCXX_STRING
	_OP(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
#define _S
#endif
	_OP(char){char c=gcu();gcu();return c;}
	_OP(double){double d; scanf("%lf",&d); gcu();return d;}
	_T _OP(T){T n{},m{1},c;while(isspace(c = gcu()));if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
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
#define dbg(...) fprintf(stderr,__VA_ARGS__)
struct range{
	int e,b=0,s=1;range(int b,int e,int s):e(e),b(b),s(s){} range(int b,int e): e(e), b(b){} range(int e):e(e){}
	struct it{int v,s; it(int v,int s):v(v),s(s){} operator int()const{return v;} operator int&(){return v;}int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

_T using V = vector<T>;
using P = complex<int>;

int square (int a) {
	return a * a;
}

int main() {
	for (int n; (n = in);) {
		V<P> v(n);
		V<V<bool>> m(5001, V<bool>(5001));
		for (int i: range(n)) {
			int x {in}, y {in};
			v[i] = {x, y};
			m[y][x] = true;
		}
		auto check = [&](P a) {
			int x {real(a)}, y {imag(a)};
			return x >= 0 && x < 5001 && y >= 0 && y < 5001 && m[y][x];
		};
		int r {};
		for (auto p1 {begin(v)}; p1 != end(v); p1++)
			for (auto p2 {next(p1)}; p2 != end(v); p2++)
				if (p1 != p2) {
					P d {(*p1 - *p2) * P{0, 1}};
					if (check(*p1 + d) && check(*p2 + d))
						r = max(r, square(real(d)) + square(imag(d)));
				}
		outl(r);
	}
}

/* vim: set ts=4 noet: */

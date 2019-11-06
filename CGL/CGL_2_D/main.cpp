#include <cstdio>
#include <utility>
#include <cctype>
#include <algorithm>
#include <complex>
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
	struct range{
		int e,b=0,s=1;range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
		struct it{int v,s; it(int _v,int _s):v(_v),s(_s){} operator int()const{return v;} operator int&(){return v;}int operator*()const{return v;}
			it& operator++(){v+=s;return *this;} }; it begin(){return {b,s};} it end(){return {e,s};}};
#define times(i,n) for(int i=n;i;i--)

using P = complex<double>;

P read() {
	int x {in}, y {in};
	return P(x, y);
}

void outl(P a) {
	printf("(%f, %f)\n", real(a), imag(a));
}

void outl(double a) {
	printf("%.10f\n", a);
}

double dot(P a, P b) {
	return real(a * conj(b));
}
double cross(P a, P b) {
	return imag(a * conj(b));
}

int ccw(P a, P b, P c) {
	b -= a; c -= a, a = b * conj(c);
	return imag(a) > 0 ? 1 : imag(a) < 0 ? -1 : real(a) < 0 ? 2 : norm(b) < norm(c) ? -2 : 0;
}

bool intersection(P &p0, P &p1, P &p2, P &p3) {
	return (ccw(p1, p0, p2) * ccw(p1, p0, p3) <= 0) && (ccw(p3, p2, p0) * ccw(p3, p2, p1) <= 0);
}

double distance(P a, P b, P p) {
	if (dot(b - a, p - a) < 0)
		return abs(p - a);
	else if (dot(a - b, p - b) < 0)
		return abs(p - b);
	else
		return abs(cross(b - a, p - a) / abs(b - a));
}

double distance(P a, P b, P c, P d) {
	if (intersection(a, b, c, d))
		return 0.;
	else
		return min(min(distance(a, b, c), distance(a, b, d)),
				   min(distance(c, d, a), distance(c, d, b)));
}

int main() {
	times (q, in) {
		P p0 {read()}, p1 {read()}, p2 {read()}, p3 {read()};
		outl(distance(p0, p1, p2, p3));
	}
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <utility>
#include <string>
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
	_OP(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n'&&c!=EOF;)s+=c;return s;}
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

struct O {
	string s;
	bool q;
};

O strip (string::iterator &i, string::iterator e) {
	O o;
	if (*i == '\"') {
		o.q = true;
		i++;
		while (*i != '\"')
			o.s.push_back(*i++);
		i++;
	} else {
		o.q = false;
		while (*i != '\"' && i != e)
			o.s.push_back(*i++);
	}
	return o;
}

int main() {
	for (;;) {
		string s1 = in, s2 = in;
		if (s1 == ".")
			return 0;
		[&] {
			bool f {};
			for (auto i1 {begin(s1)}, i2 {begin(s2)}; i1 != end(s1) || i2 != end(s2);) {
				O o1 {strip(i1, end(s1))}, o2 {strip(i2, end(s2))};
				if (o1.q && o2.q && o1.s != o2.s) {
					if (f) {
						outl("DIFFERENT");
						return;
					} else
						f = true;
				} else if (o1.s != o2.s || o1.q != o2.q) {
					outl("DIFFERENT");
					return;
				}
			}
			outl(f ? "CLOSE" : "IDENTICAL");
		}();
	}
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <cctype>
#include <utility>
#include <array>
#include <functional>
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
#define _ot _il void out
#define _ol _il void outl
_ot(bool b) {pcu('0'+b);}
_ot(const char *s){while(*s)pcu(*s++);}
_ot(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_ot(string s){for(char c:s)pcu(c);}
#endif
_T _ot(T n){static char buf[20];char *p=buf;if(n<0)pcu('-'),n*=-1;
	if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10; while (p!=buf)pcu(*--p);}
_ol(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _ot(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _ot(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _ol(T&&... t){out(move(t)...);outl();}

struct T {int r, i[3], j[3];};

int main() {
	array<string, 8> a;
	for (auto &y: a)
		scan(y);
	const T tr[] = {90, {7, -1, -1}, {0, 8, 1},
		180, {7, -1, -1}, {7, -1, -1}, 270, {0, 8, 1}, {7, -1, -1}};
	auto loop = [](int o[], auto f) {
		for (int i = o[0]; i != o[1]; i = plus<int>()(i, o[2]))
			f(i);};
	for (T t: tr) {
		outl(t.r);
		loop(t.i, [&](int i){
			 loop(t.j, [&](int j){
				  out(a[i][j]);});
			 outl();;});
	}
}

/* vim: set ts=4 noet: */

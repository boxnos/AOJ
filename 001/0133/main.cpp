#include <cstdio>
#include <cctype>
#include <utility>
#include <array>
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

int main() {
	array<string, 8> a;
	for (auto &y: a)
		scan(y);
	int i, j, go[] = {0, 8, 1}, back[] = {7, -1, -1};
	const struct {int r, *i, *j, &x, &y;} tr[] =
		{90, go, back, i, j, 180, back, back, j, i, 270, back, go, i, j};
	auto loop = [](int o[], int &k, auto f) {
		for (k = o[0]; k != o[1]; k += o[2]) f();};
	for (auto &t: tr) {
		outl(t.r);
		loop(t.i, i, [&] {
			 loop(t.j, j, [&] {
				  out(a[t.y][t.x]);});
			 outl();});
	}
}

/* vim: set ts=4 noet: */

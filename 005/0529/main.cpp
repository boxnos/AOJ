#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
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

void radix_sort(vector<int>::iterator b,vector<int>::iterator e) {
    vector<int> t(e - b);
    array<int, 256> c, s;
    for (int i = 0; i < 32; i += 8) {
        fill(c.begin(), c.end(), 0);
        for_each(b, e, [&](int j) {c[(j >> i) & 255]++;});
        s[0] = 0;
        partial_sum(c.begin(), c.end() - 1, s.begin() + 1);
        for_each(b, e, [&](int j) {t[s[(j >> i) & 255]++] = j;});
        copy(t.begin(), t.end(), b);
    }
}

int main() {
	for (int N, M; N = in(), M = in();) {
		vector<int> t(N), u;
		for (int &p: t)
			p = in();
		t.push_back(0);
		for (auto i = t.begin(); i != t.end(); i++)
			for (auto j = i; j != t.end(); j++)
				if (*i + *j <= M)
					u.push_back(*i + *j);
		radix_sort(u.begin(), u.end());
		int r = 0;
		for (auto i = u.begin(), e = u.end() - 1; i <= e; i++) {
			for (; *i + *e >= M; e--)
				;
			r = max(r, *i + *e);
		}
		outl(r);
	}
}

/* vim: set ts=4 noet: */

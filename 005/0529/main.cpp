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

#define all(o) o.begin(), o.end()

void radix_sort(vector<int> &v) {
	vector<int> t(v.size());
	array<int, 256> c, s;
	for (int i = 0; i < 32; i += 8) {
		fill(all(c), 0);
		for_each(all(v), [&](int j) {c[(j >> i) & 255]++;});
		s.front() = 0;
		partial_sum(all(c) - 1, s.begin() + 1);
		for_each(all(v), [&](int j) {t[s[(j >> i) & 255]++] = j;});
		swap(v, t);
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
		radix_sort(u);
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

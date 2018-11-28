#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define gcu getchar_unlocked
int in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
int in() {return in(gcu());}
bool scan(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
bool scan(char &c){c=gcu();gcu();return c!=EOF;}
//bool scan(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
template <typename head, typename... tail>
bool scan(head &h, tail&&... t){return scan(h) && scan(t...);}
#define pcu putchar_unlocked
#define vo inline void out
template <typename T>
vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
vo(const char *s){while(*s)pcu(*s++);}
vo(char c){pcu(c);}
//vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

typedef tuple<int, int, int> P;
enum {D, H, W, N = 150};

int main() {
	vector<P> p;
	for (int i = 1; i < N; i++)
		for (int j = i + 1; j < N; j++)
			p.push_back({i * i + j * j, i, j});
	sort(p.begin(), p.end());
	for (int w, h; w = in(), h = in(), w || h;) {
		auto r = upper_bound(p.begin(), p.end(), P{w * w + h * h, w, h});
		out(get<H>(*r), ' ', get<W>(*r), '\n');
	}
}

/* vim: set ts=4 noet: */

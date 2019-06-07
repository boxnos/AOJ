#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <climits>
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

int main() {
	int V{in()}, inf{INT_MAX};
	vector<vector<int>> v(V, vector<int>(V, inf));
	auto loop = [&](auto f) {
		for (int i{0}; i < V; i++)
			f(i);};
	loop([&](int i) {
		 v[i][i] = 0;});
	for (int E{in()}; E; E--) {
		int s = in(), t = in(), d = in();
		v[s][t] = d;
	}
	loop([&](int k) {
		 loop([&](int i) {
			  loop([&](int j) {
				   if (v[i][k] < inf && v[k][j] < inf)
						v[i][j] = min(v[i][j], v[i][k] + v[k][j]);});});});
	if ([&]{
		for (int i{0}; i < V; i++)
			if (v[i][i] < 0)
				return false;
		return true;}())
		for (auto &y: v) {
			for (int &x: y) {
				out(&x == &y[0] ? "": " ");
				if (x < inf)
					out(x);
				else
					out("INF");
			}
			outl();
		}
	else
		outl("NEGATIVE CYCLE");
}

/* vim: set ts=4 noet: */

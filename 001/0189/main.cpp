#include <cstdio>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in(gcu());}
_sc(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
//_sc(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
template <typename H,typename... T> _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
template <typename T>
_vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
//_vo(string &s){for (char c: s) pcu(c);}
template <typename H,typename... T> _vo(H&& h, T&&... t){out(h);out(move(t)...);}
//template <typename T> _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
_vl(){out('\n');}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

int main() {
	for (int n; (n = in());) {
		vector<vector <int>> v(10, vector<int>(10, INT_MAX/2));
		int s = 0;
		while (n--) {
			int a = in(), b = in();
			v[a][b] = v[b][a] = in();
			s = max(s, max(a, b));
		}
		s++;
		for (int i = 0; i < s; i++)
			v[i][i] = 0;
		for (int k = 0; k < s; k++)
			for  (int i = 0; i < s; i++)
				for (int j = 0; j < s; j++)
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
		int ri = 0, rm = INT_MAX;
		for (int i = 0; i < s; i++) {
			int m = 0;
			for (int j = 0; j < s; j++)
				m += v[i][j];
			if (m < rm)
				ri = i, rm = m;
		}
		outl(ri, ' ', rm);
	}
}

/* vim: set ts=4 noet: */

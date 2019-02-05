#include <cstdio>
#include <utility>
#include <map>
#include <string>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
//_vo(string &s){for(char c:s)pcu(c);}
_vo(string s){for(char c:s)pcu(c);}
_T _vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
//_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

int main() {
	map<string, int> m;
	string k;
	for (int i = in(); i; i--) {
		int o = in();
		scan(k);
		switch(o) {
		case 0:
			m[k] = in();
			break;
		case 1:
			{ auto r = m.find(k); outl(r != m.end() ? r->second : 0); }
			break;
		case 2:
			m.erase(k);
			break;
		case 3:
			string s;
			scan(s);
			for (auto i = m.lower_bound(k), e = m.upper_bound(s); i != e; i++)
				outl(i->first, ' ', i->second);
		}
	}
}

/* vim: set ts=4 noet: */

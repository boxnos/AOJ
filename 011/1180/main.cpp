#include <cstdio>
#include <utility>
#include <string>
#include <algorithm>
#include <unordered_map>
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
vo(string &s){for (char c: s) pcu(c);}
template <typename head, typename... tail> vo(head&& h, tail&&... t){out(h);out(move(t)...);}
//template <typename T> vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
#undef vo

int main() {
	for (int a, l; a = in(), l = in(), a || l;) {
		int b, c = 0;
		unordered_map<int, int> m;
		string v(l, '0');
		do {
			m[a] = c++;
			for (int i = l - 1; ~i; i--, a /= 10)
				v[i] = a % 10 + '0';
			sort(v.begin(), v.end());
			b = stoi(v);
			reverse(v.begin(), v.end());
		} while (!m.count(a = stoi(v) - b));
		out(m[a], ' ' , a,' ', c - m[a], '\n');
	}
}

/* vim: set ts=4 noet: */

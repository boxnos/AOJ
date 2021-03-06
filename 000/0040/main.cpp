#include <cstdio>
#include <cctype>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _T template <typename T>
#define _HT template <typename H, typename... T>
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_T T in(int c){T n=0;bool m=false;
	while (isspace(c)) {c = gcu();}
	if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in<int>(gcu());}
_T T scan(T &n){int c=gcu();return c==EOF?false:(n=in<T>(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
#ifdef _GLIBCXX_STRING
_sc(string &s){int c;s="";
	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
#endif
_HT _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
_vo(bool b) {pcu('0'+b);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_vo(string s){for(char c:s)pcu(c);}
#endif
_T _vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vl(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);outl();}
#endif
_HT _vo(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

using S = string;
using K = pair<int, int>;

void decode(S s, K k) {
	vector<char> t(26);
	for (int i = 0; i < 26; i++)
		t[(i * k.first + k.second) % 26] = i;
	for (char &c: s)
		pcu(islower(c) ? t[c - 'a'] + 'a' : c);
	outl();
}

K attack(S s) {
	S w;
	for (char c: s) {
		if(islower(c))
			w += c;
		else {
			if (w.size() == 4)
				for (int a = 1; a < 26; a += 2)
					if (a != 13) {
						int b = (26 + w[0] - 'a' - ('t' - 'a') * a % 26) % 26;
						auto d = [=](int c) {return ((c - 'a') * a + b) % 26 + 'a';};
						if (w[1] == d('h') &&
							((w[2] == d('a') && w[3] == d('t')) ||
							 (w[2] == d('i') && w[3] == d('s'))))
							return {a, b};
					}
			w = "";
		}
	}
	return {0, 0};
}

int main() {
	for (int n = in(); n; n--) {
		S s;
		getline(cin, s);
		decode(s, attack(s + ' '));
	}
}

/* vim: set ts=4 noet: */

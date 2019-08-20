#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

#define _gp(l) const auto gcu{getchar##l}; const auto pcu{putchar##l}
#ifdef __linux
_gp(_unlocked);
#else
_gp();
#endif
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template <typename T>
#define _HT template <typename H,typename... T>
#define _OP(t) inline operator t()
struct _in {
#ifdef _GLIBCXX_STRING
	_OP(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n';)s+=c;return s;}
#endif
	_OP(char){char c=gcu();gcu();return c;}
	_OP(double){double d; scanf("%lf",&d); gcu();return d;}
	_T _OP(T){T n{},m{1},c;if((c=gcu())=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
} in;
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_T _SCAN(T &o) {int c{gcu()};return c==EOF?false:(ungetc(c,stdin),o=in,true);}
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_OUT(string &s){for(char c:s)pcu(c);}
#endif
_T _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;
	if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H &&h, T... t){out(h);out(t...);}
template <typename... T> _OUTL(T... t){out(t...);outl();}
struct range{
	int e,b=0,s=1; range(int _b,int _e,int _s):e(_e),b(_b),s(_s){} range(int _b,int _e): e(_e), b(_b){} range(int _e):e(_e){}
	struct it { int v, s; it (int _v, int _s) : v(_v), s(_s) {} operator int()const{return v;} operator int&(){return v;} int operator*()const{return v;}
		it& operator++(){v+=s;return *this;} }; it begin() {return {b, s};} it end() {return {e, s};}};
unordered_map<char, string> enc = {
	{' ', "101"}, {'\'', "000000"}, {',', "000011"}, {'-', "10010001"}, {'.', "010001"},
	{'?', "000001"}, {'A', "100101"}, {'B', "10011010"}, {'C', "0101"}, {'D', "0001"},
	{'E', "110"}, {'F', "01001"}, {'G', "10011011"}, {'H', "010000"}, {'I', "0111"},
	{'J', "10011000"}, {'K', "0110"}, {'L', "00100"}, {'M', "10011001"}, {'N', "10011110"},
	{'O', "00101"}, {'P', "111"}, {'Q', "10011111"}, {'R', "1000"}, {'S', "00110"},
	{'T', "00111"}, {'U', "10011100"}, {'V', "10011101"}, {'W', "000010"}, {'X', "10010010"},
	{'Y', "10010011"}, {'Z', "10010000"} };

int main() {
	string s;
	while(getline(cin, s)) {
		deque<bool> b;
		for (char c: s)
			for (char d: enc[c])
				b.push_back(d - '0');
		if (b.size() % 5)
			for (int i = 5 - b.size() % 5; i; i--)
				b.push_back(false);
		for (int i: range(b.size() / 5)) {
			int t {};
			for (int j: range(5))
				t = t << 1 | b[i * 5 + j];
			out((char) (t < 26 ? t + 'A' : " .,-'?"[t - 26]));
		}
		outl();
	}
}

/* vim: set ts=4 noet: */

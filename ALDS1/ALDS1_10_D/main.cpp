#include <cstdio>
#include <cctype>
#include <cfloat>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true; else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	//return n; }
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
template <typename T>
svo(T n) {
	static char buf[20];
	char *p = buf;
	//if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
//svo(vector<T> &v){for(T &x:v)out(' '),out(x);out('\n');}
svo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}
#undef svo
#undef si

#define v vector

struct OBST {
	typedef vector<double> vd;
	vd p, q;
	v<vd> e, w;

	void read(int n) {
		p.resize(n + 1);
		q.resize(n + 1);
		for (int i = 1; i <= n; i++)
			scanf("%lf", &p[i]);
		for (int i = 0; i <= n; i++)
			scanf("%lf", &q[i]);
	}

	double cost(int n) {
		e = v<vd>(n + 2, vd(n + 1));
		w = v<vd>(n + 2, vd(n + 1));
		for (int i = 0; i <= n; i++) {
			e[i + 1][i] = q[i];
			w[i + 1][i] = q[i];
		}
		for (int l = 1; l <= n; l++)
			for (int i = 1; i <= n - l + 1; i++) {
				int j = i + l - 1;
				e[i][j] = DBL_MAX;
				w[i][j] = w[i][j - 1] + p[j] + q[j];
				for (int r = i; r <= j; r++)
					e[i][j] = min(e[i][j], e[i][r - 1] + e[r + 1][j] + w[i][j]);
			}
		return e[1][n];
	}
};

int main() {
	int n = in();
	OBST obst;
	obst.read(n);
	printf("%.8lf\n", obst.cost(n));
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;

#define si static inline
#define gcu getchar_unlocked
si int in() {
	int c, n = 0;
	bool minus = false;
	if ((c = gcu()) == '-') minus = true;
	else ungetc(c, stdin);
	while ((c = gcu()) >= '0' && c <= '9') n = 10 * n + (c - '0');
	return minus ? -n : n; }
si void scan(char *s) {while (!isspace(*s++ = gcu()));}
#define pcu putchar_unlocked
#define svo si void out
svo(int n) {
	static char buf[20];
	char *p = buf;
	if(n < 0) pcu('-'), n *= -1;
	if (!n) *p++ = '0';
	else while (n) *p++ = n % 10 + '0', n /= 10;
	while (p != buf) pcu(*--p); }
svo(const char *s){while(*s)pcu(*s++);}
//svo(char *s){while(*s)pcu(*s++);}
svo(char c){pcu(c);}
template <typename T>
svo(vector<T> v){for(T &x:v)out(' '),out(x);out('\n');}
//svo(vector<T> &v){for(int &x:v)out(&x == &v[0]?"":" ",x);out('\n');}
template <typename head, typename... tail>
svo(head&& h, tail&&... t){out(h);out(move(t)...);}

typedef vector<int> v;

template <typename T>
struct tree {
	struct node {
		T v;
		int p;
		node *n[2];

		node(T x, T p) {
			v = x;
			this->p = p;
			n[0] = n[1] = nullptr;
		}
	};

	typedef node N;
	N *root = nullptr;

	N* rotate(N* r, int b) {
		N *s = r->n[1 - b];
		r->n[1 - b] = s->n[b];
		s->n[b] = r;
		return s;
	}
	N* insert(int k, int p, N *t) {
		if (!t)
			return new N(k, p);
		int b = !(k < t->v);
		t->n[b] = insert(k, p, t->n[b]);
		return (t->p < t->n[b]->p) ? rotate(t, 1 - b) : t;
	}
	void insert(T k, T p) {
		root = insert(k, p, root);
	}
	N* _erace(N *r, T x) {
		if (!r->n[0] && !r->n[1])
			r = nullptr;
		else if (!r->n[0])
			r = rotate(r, 0);
		else if (!r->n[1])
			r = rotate(r, 1);
		else
			r = rotate(r, r->n[0]->p > r->n[1]->p);
		return erace(r, x);
	}
	N* erace(N *r, T x) {
		if (!r)
			;
		else if (r->v == x)
			r = _erace(r, x);
		else if (r->v > x)
			r->n[0] = erace(r->n[0], x);
		else
			r->n[1] = erace(r->n[1], x);
		return r;
	}
	void erace(T x) {
		root = erace(root, x);
	}
	bool find(N *r, T x) {
		if (r == nullptr)
			return false;
		else if (r->v == x)
			return true;
		else if (r->v > x)
			return find(r->n[0], x);
		else
			return find(r->n[1], x);
	}
	bool find(T x) {
		return find(root, x);
	}
	void print(N *r, v &buf) {
		if (r == nullptr)
			return;
		buf.push_back(r->v);
		print(r->n[0], buf);
		out(' ', r->v);
		print(r->n[1], buf);
	}
	void print() {
		v buf;
		print(root, buf);
		out('\n', buf);
	}
};

int main() {
	int n = in(), x;
	char s[20];
	tree<int> b;

	while (n--) {
		scan(s);
		switch(*s) {
		case 'i':
			x = in();
			b.insert(x, in()); break;
		case 'f':
			out(b.find(in()) ? "yes\n": "no\n"); break;
		case 'd':
			b.erace(in()); break;
		default:
			b.print();
		}
	}
}

/* vim: set ts=4 noet: */

#include <cstdio>
#include <random>
using namespace std;

random_device rd;
mt19937 mt(rd());

template <typename T>
struct tree
{
	struct node
	{
		T v;
		int c, p;
		node *n[2];

		node(T x)
		{
			v = x;
			c = 1;
			p = mt();
			n[0] = n[1] = nullptr;
		}
	};

	typedef node N;
	N *root;
	long counter;

	tree()
	{
		root = nullptr;
		counter = 0;
	}

	inline int count(N *n) {return n ? n->c : 0;}

	N* rotate(N* r, int b) 
	{
		N *s = r->n[1 - b];

		r->c += count(s->n[b]) - count(r->n[1 - b]);
		r->n[1 - b] = s->n[b];

		s->c += r->c - count(s->n[b]);
		s->n[b] = r;
		return s;
	}

	N* insert(int x, N *t, int cnt)
	{
		if (!t) {
			counter += cnt;
			return new N(x);
		}
		int b = !(x < t->v);
		if (b)
			cnt -= 1 + count(t->n[0]);
		t->n[b] = insert(x, t->n[b], cnt);
		t->c++;
		return (t->p > t->n[b]->p) ? rotate(t, 1 - b) : t;
	}

	void insert(T x)
	{
		root = insert(x, root, count(root));
	}
};

static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
    return n;
}

int main()
{
	int	n = in();

	tree<int> t;
	while (n--)
		t.insert(in());

	printf("%ld\n", t.counter);
}

/* vim: set ts=4 noet: */

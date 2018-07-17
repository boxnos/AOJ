#include <cstdio>
using namespace std;

template <class T>
struct node {
	T v;
	int c;
	node *l, *r;
	node(T x)
	{
		v = x;
		c = 1;
		l = r = nullptr;
	}
};

template <class T>
struct tree {
	typedef node<T> N;
	N *root;
	long counter;
	tree() {
		root = nullptr;
		counter = 0;
	}
	void insert(N *n, N *t, int cnt)
	{
		if (n->v < t->v)
			if (t->l)
				insert(n, t->l, cnt);
			else
				t->l = n, counter += cnt;
		else
			if (t->r)
				insert(n, t->r, cnt - 1 - (t->l ? t->l->c : 0));
			else
				t->r = n, counter += cnt - 1 - (t->l ? t->l->c : 0);
		t->c++;
	}
	void insert(T x)
	{
		N *n = new N(x);
		if (root)
			insert(n, root, root->c);
		else
			root = n;
	}
};

int main()
{
	int	n, x;
	scanf("%d", &n);

	tree<int> t;
	while (n--) {
		scanf("%d", &x);
		t.insert(x);
	}

	printf("%ld\n", t.counter);
}

/* vim: set ts=4 noet: */

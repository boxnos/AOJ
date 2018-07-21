#include <cstdio>
#include <array>
using namespace std;

typedef array<int, 10001> v;

static inline int in()
{
    int c, n = 0;
    while ((c = getchar_unlocked()) >= '0' && c <= '9')
		n = 10 * n + (c - '0');
    return n;
}

int main()
{
	int n = in(), c = n;

	v b = {};

	while (n--)
		b[in()]++;

	bool f = true;
	for (int i = 0; c; i++)
		while (b[i]--)
			printf("%s%d", (f? f = false, "": " "), i), c--;
	puts("");
}

/* vim: set ts=4 noet: */

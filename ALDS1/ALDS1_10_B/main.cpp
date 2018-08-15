#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct matrix {int r, c;};
typedef matrix M;
#define v vector
typedef v<int> vi;
typedef v<vi> vvi;
typedef v<M> vm;

vm m;
vvi t;

int McM(int b, int e) {
	int r = t[b][e];
	if (r != INT_MAX)
		return r;
	if (b == e)
		r = 0;
	else
		for (int i = b; i < e; i++)
			r = min(r, McM(b, i) + McM(i + 1, e) + m[b].r * m[i].c * m[e].c);
	t[b][e] = r;
	return r;
}

int main() {
	int n;
	cin >> n;
	m = vm(n);
	t = vvi(n, vi(n, INT_MAX));
	for (M &x: m)
		cin >> x.r >> x.c;
	cout << McM(0, n - 1) << endl;
}

/* vim: set ts=4 noet: */

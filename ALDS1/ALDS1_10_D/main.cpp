#include <cstdio>
#include <cfloat>
#include <vector>
using namespace std;

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
	int n;
	scanf("%d", &n);
	OBST obst;
	obst.read(n);
	printf("%.8lf\n", obst.cost(n));
}

/* vim: set ts=4 noet: */
